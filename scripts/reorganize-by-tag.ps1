param(
    [switch]$Execute,
    [int]$ThrottleMilliseconds = 120
)

$ErrorActionPreference = 'Stop'

$root = (Get-Location).Path
$difficultyMap = [ordered]@{
    'Easy' = 'easy'
    'Medium' = 'medium'
    'Hard' = 'hard'
    'unfinished' = 'unfinished'
}

$apiUri = 'https://leetcode.com/graphql'
$graphqlQuery = 'query questionData($titleSlug: String!) { question(titleSlug: $titleSlug) { topicTags { slug } } }'
$tagCache = @{}

function Get-TitleSlug {
    param(
        [Parameter(Mandatory = $true)][string]$FileName
    )

    $base = [System.IO.Path]::GetFileNameWithoutExtension($FileName)
    if ($base -notmatch '^\d+\.(.+)$') {
        return $null
    }

    $titlePart = $Matches[1]
    $titlePart = $titlePart -replace '\.', '-'
    $titlePart = $titlePart -replace '_', '-'
    $titlePart = $titlePart -creplace '([a-z0-9])([A-Z])', '$1-$2'
    $titlePart = $titlePart.ToLowerInvariant()
    $titlePart = $titlePart -replace '[^a-z0-9-]', '-'
    $titlePart = $titlePart -replace '-+', '-'
    $titlePart = $titlePart.Trim('-')

    if ([string]::IsNullOrWhiteSpace($titlePart)) {
        return $null
    }

    return $titlePart
}

function Get-PrimaryTagSlug {
    param(
        [Parameter(Mandatory = $true)][string]$TitleSlug
    )

    if ($tagCache.ContainsKey($TitleSlug)) {
        return $tagCache[$TitleSlug]
    }

    $payload = @{
        query = $graphqlQuery
        variables = @{ titleSlug = $TitleSlug }
    } | ConvertTo-Json -Depth 5

    try {
        $response = Invoke-RestMethod -Uri $apiUri -Method Post -ContentType 'application/json' -Body $payload
        $tag = $response.data.question.topicTags[0].slug
        if ([string]::IsNullOrWhiteSpace($tag)) {
            $tag = 'uncategorized'
        }
    }
    catch {
        $tag = 'uncategorized'
    }

    $tagCache[$TitleSlug] = $tag
    Start-Sleep -Milliseconds $ThrottleMilliseconds
    return $tag
}

$fileMoves = New-Object System.Collections.Generic.List[object]

foreach ($sourceDifficulty in $difficultyMap.Keys) {
    $sourcePath = Join-Path $root $sourceDifficulty
    if (-not (Test-Path -LiteralPath $sourcePath)) {
        continue
    }

    $targetDifficulty = $difficultyMap[$sourceDifficulty]
    $files = Get-ChildItem -LiteralPath $sourcePath -File -Recurse

    foreach ($file in $files) {
        $slug = Get-TitleSlug -FileName $file.Name
        $tagSlug = if ($slug) { Get-PrimaryTagSlug -TitleSlug $slug } else { 'uncategorized' }
        $targetDir = Join-Path (Join-Path $root $tagSlug) $targetDifficulty
        $targetPath = Join-Path $targetDir $file.Name

        $fileMoves.Add([pscustomobject]@{
            Source = $file.FullName
            TargetDir = $targetDir
            TargetPath = $targetPath
            Tag = $tagSlug
            Difficulty = $targetDifficulty
        })
    }
}

$conflicts = $fileMoves | Where-Object { Test-Path -LiteralPath $_.TargetPath }

Write-Host "Found $($fileMoves.Count) file(s) to process."
Write-Host "Unique tags: $((($fileMoves | Select-Object -ExpandProperty Tag -Unique) | Sort-Object).Count)"

if ($conflicts.Count -gt 0) {
    Write-Warning "Found $($conflicts.Count) conflict(s) where target file already exists. These files will be skipped."
}

if (-not $Execute) {
    Write-Host 'Preview mode (no files moved).'
    $fileMoves |
        Select-Object -First 30 Source, TargetPath |
        Format-Table -AutoSize
    Write-Host "Run with -Execute to apply changes."
    return
}

$moved = 0
$skipped = 0

foreach ($move in $fileMoves) {
    if (Test-Path -LiteralPath $move.TargetPath) {
        $skipped++
        continue
    }

    if (-not (Test-Path -LiteralPath $move.TargetDir)) {
        New-Item -ItemType Directory -Path $move.TargetDir -Force | Out-Null
    }

    Move-Item -LiteralPath $move.Source -Destination $move.TargetPath
    $moved++
}

Write-Host "Moved: $moved"
Write-Host "Skipped (conflicts): $skipped"
Write-Host 'Done.'