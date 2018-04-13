param (
    [string]$nodeVersion
)


ForEach($version in Get-Command node -Type Application)
{
    if ($version.Version -eq "$($nodeVersion).0")
    {
        $nodeInfo = $version
    }
}

Write-Host $nodeInfo
$nodeExe = $nodeInfo.Source
Write-Host "Node exe is " $nodeExe
Write-Host "Node version is " $nodeVersion

$ruleName = "Node $($nodeVersion) UDP"

$existingRule = Get-NetFirewallRule -DisplayName $ruleName

if ($existingRule.length -ne 0)
{
    Write-Host "Rule exists, removing"
    Remove-NetFirewallRule -DisplayName $ruleName
}

Write-Host "Running New-NetFirewallRule with args -DisplayName $($ruleName) -Direction Inbound  -Protocol UDP -Action Allow -Program $($nodeExe)"
New-NetFirewallRule -DisplayName $ruleName -Direction Inbound  -Protocol UDP -Action Allow -Program $nodeExe
 
$ruleInfo = Get-NetFirewallRule -DisplayName $ruleName | Get-NetFirewallApplicationFilter
Write-Host $ruleInfo.AppPath