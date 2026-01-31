// CityPlacementMode.cpp

#include "CityPlacementMode.h"

#include "Editor.h"
#include "EditorViewportClient.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"


// Unique ID for this editor mode
const FEditorModeID FCityPlacementMode::EM_CityPlacement =
TEXT("EM_CityPlacement");


// Constructor
FCityPlacementMode::FCityPlacementMode()
{
    UE_LOG(LogTemp, Warning, TEXT("CityPlacementMode Constructor"));
}

// Destructor
FCityPlacementMode::~FCityPlacementMode()
{
}


// Called when mode is activated
void FCityPlacementMode::Enter()
{
    FEdMode::Enter();

    UE_LOG(LogTemp, Warning, TEXT("CityPlacementMode Entered"));
}


// Called when mode is deactivated
void FCityPlacementMode::Exit()
{
    UE_LOG(LogTemp, Warning, TEXT("CityPlacementMode Exited"));

    FEdMode::Exit();
}


// Handle mouse clicks in viewport
bool FCityPlacementMode::HandleClick(
    FEditorViewportClient* InViewportClient,
    HHitProxy* HitProxy,
    const FViewportClick& Click
)
{
    if (!InViewportClient)
        return false;

    UWorld* World = InViewportClient->GetWorld();
    if (!World)
        return false;


    // Build scene view
    FSceneViewFamilyContext ViewFamily(
        FSceneViewFamily::ConstructionValues(
            InViewportClient->Viewport,
            InViewportClient->GetScene(),
            InViewportClient->EngineShowFlags
        ).SetRealtimeUpdate(true)
    );

    FSceneView* View = InViewportClient->CalcSceneView(&ViewFamily);

    if (!View)
        return false;


    // Convert screen pos to ray
    FVector RayOrigin;
    FVector RayDirection;

    View->DeprojectFVector2D(
        Click.GetClickPos(),
        RayOrigin,
        RayDirection
    );


    FVector RayEnd = RayOrigin + RayDirection * 200000.f;

    FHitResult Hit;


    bool bHit = World->LineTraceSingleByChannel(
        Hit,
        RayOrigin,
        RayEnd,
        ECC_Visibility
    );


    if (bHit)
    {
        FVector HitPoint = Hit.ImpactPoint;

        UE_LOG(
            LogTemp,
            Warning,
            TEXT("Placement Hit: %s"),
            *HitPoint.ToString()
        );

        DrawDebugSphere(
            World,
            HitPoint,
            25.f,
            12,
            FColor::Green,
            false,
            2.f
        );
    }

    return true;
}
