// CityPlacementMode.cpp

#include "CityPlacementMode.h"

// Core editor
#include "Editor.h"
#include "UnrealEd.h"

// Viewport / rendering
#include "EditorViewportClient.h"
#include "SceneView.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

// Debug
#include "DrawDebugHelpers.h"

// Math
#include "Math/UnrealMathUtility.h"

#include "CityPlacementControllerBase.h"
#include "EngineUtils.h"
#include "CityPlacementSettingsSubsystem.h"


// Unique ID for this editor mode
const FEditorModeID FCityPlacementMode::EM_CityPlacement =
TEXT("EM_CityPlacement");


// Constructor
FCityPlacementMode::FCityPlacementMode()
{
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

float FCityPlacementMode::GetLiveGridSize() const
{
#if WITH_EDITOR
    if (GEditor)
    {
        if (UCityPlacementSettingsSubsystem* Subsys =
            GEditor->GetEditorSubsystem<UCityPlacementSettingsSubsystem>())
        {
            return Subsys->GetGridSize();
        }
    }
#endif

    return 500.f; // fallback
}


// Handle mouse clicks in viewport
bool FCityPlacementMode::HandleClick(
    FEditorViewportClient* InViewportClient,
    HHitProxy* HitProxy,
    const FViewportClick& Click
)
{
    if (!InViewportClient)
    {
        UE_LOG(LogTemp, Error, TEXT("No Viewport Client"));
        return false;
    }

    UWorld* World = nullptr;

#if WITH_EDITOR
    if (GEditor)
    {
        World = GEditor->GetEditorWorldContext().World();
    }
#endif

    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("No World"));
        return false;
    }


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
    {
        UE_LOG(LogTemp, Error, TEXT("No Scene View"));
        return false;
    }


    // Convert screen pos to world ray
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


    UE_LOG(
        LogTemp,
        Warning,
        TEXT("Trace Result: %s"),
        bHit ? TEXT("HIT") : TEXT("MISS")
    );


    if (bHit)
    {
        FVector RawPoint = Hit.ImpactPoint;

        UE_LOG(LogTemp, Warning, TEXT("Searching for controller..."));

        for (TActorIterator<ACityPlacementControllerBase> It(World); It; ++It)
        {
            ACityPlacementControllerBase* Controller = *It;

            if (!IsValid(Controller))
                continue;

            UE_LOG(LogTemp, Warning, TEXT("Found controller"));

            // Get grid size from subsystem
            float GridSize = GetLiveGridSize();

            // Snap
            FVector SnappedPoint(
                FMath::GridSnap(RawPoint.X, GridSize),
                FMath::GridSnap(RawPoint.Y, GridSize),
                RawPoint.Z
            );

            UE_LOG(
                LogTemp,
                Warning,
                TEXT("Raw: %s | Snapped: %s | Grid: %f"),
                *RawPoint.ToString(),
                *SnappedPoint.ToString(),
                GridSize
            );

            // Send to controller (it handles rotation + spawning)
            Controller->OnEditorPlacement(SnappedPoint);

            break;
        }
    }


    return true;
}