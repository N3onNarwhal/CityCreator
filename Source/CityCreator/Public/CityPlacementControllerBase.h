#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CityPlacementControllerBase.generated.h"

UCLASS(Blueprintable)
class CITYCREATOR_API ACityPlacementControllerBase : public AActor
{
	GENERATED_BODY()

public:
	ACityPlacementControllerBase();

	// This is the one we will call from the editor mode.
	// CallInEditor helps ensure the BP side is allowed to execute in editor.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, CallInEditor, Category = "CityPlacement")
	void OnEditorPlacement(FVector WorldPosition);

	virtual void OnEditorPlacement_Implementation(FVector WorldPosition);

	float GridSize = 500.f;

	UFUNCTION(BlueprintCallable, Category = "CityPlacement")
	float GetGridSize() const;

};
