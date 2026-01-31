using System;
using System.Collections.Generic;
using UnrealBuildTool;

public class CityCreatorEditorTarget : TargetRules
{
    public CityCreatorEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;

        ExtraModuleNames.AddRange(
            new string[]
            {
                "CityCreator",
                "CityCreatorEditor"
            }
        );
    }
}
