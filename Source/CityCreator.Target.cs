using System;
using System.Collections.Generic;
using UnrealBuildTool;

public class CityCreatorTarget : TargetRules
{
    public CityCreatorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;

        ExtraModuleNames.Add("CityCreator");
    }
}
