using UnrealBuildTool;

public class CityCreatorEditor : ModuleRules
{
    public CityCreatorEditor(ReadOnlyTargetRules Target)
        : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "UnrealEd",
            "Slate",
            "SlateCore",
            "EditorFramework",
            "LevelEditor"
        });

    }
}
