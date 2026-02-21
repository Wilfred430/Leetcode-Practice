param(
    [string]$RootPath = (Get-Location).Path,
    [int]$DebounceMilliseconds = 800
)

$ErrorActionPreference = 'Stop'

$updateScript = Join-Path $RootPath 'scripts\update-progress.ps1'
if (-not (Test-Path -LiteralPath $updateScript)) {
    throw "Cannot find script: $updateScript"
}

& $updateScript -RootPath $RootPath

$watcher = New-Object System.IO.FileSystemWatcher
$watcher.Path = $RootPath
$watcher.IncludeSubdirectories = $true
$watcher.EnableRaisingEvents = $true
$watcher.NotifyFilter = [System.IO.NotifyFilters]'FileName, LastWrite, DirectoryName'

$ignoreRegex = [regex]'\\(\.git|\.vscode)\\|\\scripts\\|PROGRESS\.md$|progress\.json$|\\\.vs\\'

$changed = $false

$handler = {
    param($sender, $eventArgs)
    if ($eventArgs -and $eventArgs.FullPath -and (-not $ignoreRegex.IsMatch($eventArgs.FullPath))) {
        $script:changed = $true
    }
}

$subscriptions = @(
    Register-ObjectEvent -InputObject $watcher -EventName Created -Action $handler
    Register-ObjectEvent -InputObject $watcher -EventName Changed -Action $handler
    Register-ObjectEvent -InputObject $watcher -EventName Deleted -Action $handler
    Register-ObjectEvent -InputObject $watcher -EventName Renamed -Action $handler
)

Write-Host 'Watching for changes... Press Ctrl+C to stop.'

try {
    while ($true) {
        Start-Sleep -Milliseconds $DebounceMilliseconds
        if ($changed) {
            $changed = $false
            & $updateScript -RootPath $RootPath
        }
    }
}
finally {
    foreach ($sub in $subscriptions) {
        Unregister-Event -SubscriptionId $sub.Id -ErrorAction SilentlyContinue
    }
    $watcher.Dispose()
}