#pragma once

#include "CoreMinimal.h"

// Editor mode base
#include "EdMode.h"

// Viewport / click types
#include "EditorViewportClient.h"
#include "HitProxies.h"
#include "InputCoreTypes.h"


class FCityPlacementMode : public FEdMode
{
public:

    // Unique mode ID
    static const FEditorModeID EM_CityPlacement;

    FCityPlacementMode();
    virtual ~FCityPlacementMode();


    // Lifecycle
    virtual void Enter() override;
    virtual void Exit() override;


    // Mouse input
    virtual bool HandleClick(
        FEditorViewportClient* InViewportClient,
        HHitProxy* HitProxy,
        const FViewportClick& Click
    ) override;

    float GetLiveGridSize() const;

};
