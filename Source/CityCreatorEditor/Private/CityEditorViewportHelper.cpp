#include "CityEditorViewportHelper.h"

#if WITH_EDITOR
#include "Editor.h"
#include "EditorViewportClient.h"
#include "SceneView.h"
#endif

bool UCityEditorViewportHelper::GetEditorViewportRay(
    FVector& OutOrigin,
    FVector& OutDirection
)
{
#if WITH_EDITOR

    if (!GEditor)
        return false;

    FViewport* Viewport = GEditor->GetActiveViewport();
    if (!Viewport)
        return false;

    FEditorViewportClient* ViewportClient =
        static_cast<FEditorViewportClient*>(Viewport->GetClient());
    if (!ViewportClient)
        return false;

    // Mouse position in viewport
    FIntPoint MousePos;
    Viewport->GetMousePos(MousePos);

    // Build scene view
    FSceneViewFamilyContext ViewFamily(
        FSceneViewFamily::ConstructionValues(
            Viewport,
            ViewportClient->GetScene(),
            ViewportClient->EngineShowFlags
        ).SetRealtimeUpdate(true)
    );

    FSceneView* View = ViewportClient->CalcSceneView(&ViewFamily);
    if (!View)
        return false;

    // Deproject mouse ? world
    View->DeprojectFVector2D(
        FVector2D(MousePos),
        OutOrigin,
        OutDirection
    );

    return true;

#else
    return false;
#endif
}
