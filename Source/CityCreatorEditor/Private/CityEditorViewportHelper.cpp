#include "CityEditorViewportHelper.h"

#if WITH_EDITOR

#include "Editor.h"
#include "UnrealEd.h"
#include "LevelEditorViewport.h"
#include "EditorViewportClient.h"

#endif


bool UCityEditorViewportHelper::GetEditorViewportRay(
    FVector& OutOrigin,
    FVector& OutDirection
)
{
#if WITH_EDITOR

    if (!GEditor)
    {
        return false;
    }

    FViewport* Viewport = GEditor->GetActiveViewport();

    if (!Viewport)
    {
        return false;
    }

    FEditorViewportClient* Client =
        static_cast<FEditorViewportClient*>(Viewport->GetClient());

    if (!Client)
    {
        return false;
    }

    // Get camera data
    OutOrigin = Client->GetViewLocation();
    OutDirection = Client->GetViewRotation().Vector();

    return true;

#else

    return false;

#endif
}
