#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CityEditorViewportHelper.generated.h"

UCLASS()
class CITYCREATOR_API UCityEditorViewportHelper
    : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /** Gets editor viewport ray for placement tools */
    UFUNCTION(BlueprintCallable, Category = "CityTools|Editor")
    static bool GetEditorViewportRay(
        FVector& OutOrigin,
        FVector& OutDirection
    );
};
