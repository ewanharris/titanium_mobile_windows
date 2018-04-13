$nodeInfo = Get-Command node -Type Application
$nodeExe = $nodeInfo.Source
$nodeVersion = $nodeInfo.Version
Write-Host "Node exe is " $nodeExe
Write-Host "Node version is " $nodeVersion

$ruleName = "Node $($nodeVersion) UDP"

$existingRule = Get-NetFirewallRule -DisplayName $ruleName

if ($existingRule.length -ne 0)
{
    Write-Host "Rule exists, removing"
    Remove-NetFirewallRule -DisplayName $ruleName
}
# Temporary to clean up
$existingRule = Get-NetFirewallRule -DisplayName "Node $($nodeVersion) All"

if ($existingRule.length -ne 0)
{
    Write-Host "Rule exists, removing"
    Remove-NetFirewallRule -DisplayName "Node $($nodeVersion) All"
}

# Temporary to clean up
$existingRule = Get-NetFirewallRule -DisplayName "Node $($nodeVersion) TCP"

if ($existingRule.length -ne 0)
{
    Write-Host "Rule exists, removing"
    Remove-NetFirewallRule -DisplayName "Node $($nodeVersion) TCP"
}

Write-Host "Running New-NetFirewallRule with args -DisplayName $($ruleName) -Direction Inbound  -Protocol UDP -Action Allow -Program $($nodeExe)"
New-NetFirewallRule -DisplayName $ruleName -Direction Inbound  -Protocol UDP -Action Allow -Program $nodeExe