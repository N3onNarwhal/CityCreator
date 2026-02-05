using UnrealBuildTool;

public class CityCreatorEditor : ModuleRules
{
    public CityCreatorEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "EditorSubsystem",
                "CityCreator"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "UnrealEd",
                "EditorFramework",
                "LevelEditor",
                "Slate",
                "SlateCore",
                "InputCore",
                "RenderCore",
                "RHI",
                "Renderer",
                "EditorSubsystem"
            }
        );
    }
}
