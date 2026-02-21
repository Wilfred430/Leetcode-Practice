param(
    [string]$RootPath = (Get-Location).Path,
    [string]$CommitPrefix = 'chore(progress):',
    [switch]$Push
)

$ErrorActionPreference = 'Stop'

$root = (Resolve-Path -LiteralPath $RootPath).Path
$updateScript = Join-Path $root 'scripts\update-progress.ps1'
if (-not (Test-Path -LiteralPath $updateScript)) {
    throw "Cannot find script: $updateScript"
}

Push-Location $root
try {
    & $updateScript -RootPath $root

    $status = git status --porcelain -- PROGRESS.md progress.json
    if ([string]::IsNullOrWhiteSpace(($status | Out-String))) {
        Write-Host 'No changes in PROGRESS.md/progress.json. Skip commit.'
        return
    }

    $progressPath = Join-Path $root 'progress.json'
    if (-not (Test-Path -LiteralPath $progressPath)) {
        throw 'progress.json not found after update.'
    }

    $progress = Get-Content -LiteralPath $progressPath -Raw | ConvertFrom-Json
    $solved = [int]$progress.totals.solved
    $total = [int]$progress.totals.total
    $rate = [double]$progress.completionRate
    $dateText = (Get-Date).ToString('yyyy-MM-dd')
    $commitMessage = "$CommitPrefix solved $solved/$total ($rate%) - $dateText"

    git add PROGRESS.md progress.json
    git commit -m $commitMessage

    Write-Host "Committed: $commitMessage"

    if ($Push) {
        git push
        Write-Host 'Pushed to remote.'
    }
}
finally {
    Pop-Location
}