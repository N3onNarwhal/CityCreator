#include "CityCreatorEditorModule.h"

#include "CityPlacementMode.h"
#include "EditorModeRegistry.h"
#include "Modules/ModuleManager.h"


void FCityCreatorEditorModule::StartupModule()
{
    FEditorModeRegistry::Get().RegisterMode<FCityPlacementMode>(
        FCityPlacementMode::EM_CityPlacement,
        FText::FromString("City Placement"),
        FSlateIcon(),
        true
    );
}

void FCityCreatorEditorModule::ShutdownModule()
{
    FEditorModeRegistry::Get().UnregisterMode(
        FCityPlacementMode::EM_CityPlacement
    );
}

IMPLEMENT_MODULE(FCityCreatorEditorModule, CityCreatorEditor)
