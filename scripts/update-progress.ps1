param(
    [string]$RootPath = (Get-Location).Path,
    [string]$OutputMarkdown = "PROGRESS.md",
    [string]$OutputJson = "progress.json"
)

$ErrorActionPreference = 'Stop'

$difficultyOrder = @('easy', 'medium', 'hard', 'unfinished')
$excludedRootDirs = @('.git', '.vscode', 'scripts', 'concept')

function Get-FilesCount {
    param(
        [Parameter(Mandatory = $true)][string]$Path
    )

    if (-not (Test-Path -LiteralPath $Path)) {
        return 0
    }

    return (Get-ChildItem -LiteralPath $Path -File -Recurse | Measure-Object).Count
}

$rootItem = Get-Item -LiteralPath $RootPath
$rootDirName = $rootItem.Name

$tagDirs = Get-ChildItem -LiteralPath $RootPath -Directory |
    Where-Object {
        $name = $_.Name
        -not ($excludedRootDirs -contains $name)
    } |
    Sort-Object Name

$rows = New-Object System.Collections.Generic.List[object]

foreach ($tagDir in $tagDirs) {
    $counts = [ordered]@{}
    foreach ($difficulty in $difficultyOrder) {
        $counts[$difficulty] = Get-FilesCount -Path (Join-Path $tagDir.FullName $difficulty)
    }

    $total = ($counts.Values | Measure-Object -Sum).Sum
    $solved = $total - $counts['unfinished']

    $rows.Add([pscustomobject]@{
        tag = $tagDir.Name
        easy = $counts['easy']
        medium = $counts['medium']
        hard = $counts['hard']
        unfinished = $counts['unfinished']
        solved = $solved
        total = $total
    })
}

$totals = [ordered]@{
    easy = (($rows | Measure-Object -Property easy -Sum).Sum)
    medium = (($rows | Measure-Object -Property medium -Sum).Sum)
    hard = (($rows | Measure-Object -Property hard -Sum).Sum)
    unfinished = (($rows | Measure-Object -Property unfinished -Sum).Sum)
}

$totals['solved'] = $totals.easy + $totals.medium + $totals.hard
$totals['total'] = $totals.solved + $totals.unfinished

$completionRate = if ($totals.total -eq 0) {
    0
}
else {
    [math]::Round(($totals.solved / $totals.total) * 100, 2)
}

$jsonPayload = [ordered]@{
    generatedAt = (Get-Date).ToString('o')
    workspace = $rootDirName
    totals = $totals
    completionRate = $completionRate
    byTag = $rows
}

$jsonPath = Join-Path $RootPath $OutputJson
$jsonPayload | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath $jsonPath -Encoding UTF8

$mdPath = Join-Path $RootPath $OutputMarkdown
$lines = New-Object System.Collections.Generic.List[string]

$lines.Add('# LeetCode Progress Tracker')
$lines.Add('')
$lines.Add("Updated: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')")
$lines.Add('')
$lines.Add('## Overview')
$lines.Add('')
$lines.Add("- Solved: **$($totals.solved)**")
$lines.Add("- Unfinished: **$($totals.unfinished)**")
$lines.Add("- Total: **$($totals.total)**")
$lines.Add("- Completion Rate: **$completionRate%**")
$lines.Add('')
$lines.Add('## By Difficulty')
$lines.Add('')
$lines.Add('| Easy | Medium | Hard | Unfinished |')
$lines.Add('|---:|---:|---:|---:|')
$lines.Add("| $($totals.easy) | $($totals.medium) | $($totals.hard) | $($totals.unfinished) |")
$lines.Add('')
$lines.Add('## By Tag')
$lines.Add('')
$lines.Add('| Tag | Easy | Medium | Hard | Unfinished | Solved | Total |')
$lines.Add('|---|---:|---:|---:|---:|---:|---:|')

foreach ($row in ($rows | Sort-Object -Property @(
    @{ Expression = 'total'; Descending = $true },
    @{ Expression = 'tag'; Descending = $false }
))) {
    $lines.Add("| $($row.tag) | $($row.easy) | $($row.medium) | $($row.hard) | $($row.unfinished) | $($row.solved) | $($row.total) |")
}

$lines.Add('')
$lines.Add("_Generated from folder structure: tag/easy|medium|hard|unfinished in $rootDirName._")

$lines | Set-Content -LiteralPath $mdPath -Encoding UTF8

Write-Host "Progress updated: $OutputMarkdown, $OutputJson"
Write-Host "Solved $($totals.solved) / Total $($totals.total) (Completion $completionRate%)"