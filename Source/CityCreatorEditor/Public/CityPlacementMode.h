#pragma once

#include "CoreMinimal.h"
#include "EdMode.h"

class FCityPlacementMode : public FEdMode
{
public:

    static const FEditorModeID EM_CityPlacement;

    FCityPlacementMode();
    virtual ~FCityPlacementMode();

    // Called when mode is activated
    virtual void Enter() override;
    virtual void Exit() override;

    // Mouse click handler
    virtual bool HandleClick(
        FEditorViewportClient* InViewportClient,
        HHitProxy* HitProxy,
        const FViewportClick& Click
    ) override;
};
