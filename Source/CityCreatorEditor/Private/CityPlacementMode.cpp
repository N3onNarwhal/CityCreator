#include "CityPlacementMode.h"

#include "Editor.h"
#include "EditorViewportClient.h"
#include "Engine/World.h"

const FEditorModeID FCityPlacementMode::EM_CityPlacement =
TEXT("EM_CityPlacement");


FCityPlacementMode::FCityPlacementMode()
{
}

FCityPlacementMode::~FCityPlacementMode()
{
}


void FCityPlacementMode::Enter()
{
    FEdMode::Enter();

    UE_LOG(LogTemp, Warning, TEXT("CityPlacementMode Entered"));
}

void FCityPlacementMode::Exit()
{
    UE_LOG(LogTemp, Warning, TEXT("CityPlacementMode Exited"));

    FEdMode::Exit();
}


bool FCityPlacementMode::HandleClick(
    FEditorViewportClient* InViewportClient,
    HHitProxy* HitProxy,
    const FViewportClick& Click
)
{
    UE_LOG(LogTemp, Warning, TEXT("Viewport Clicked"));

    return true;
}
