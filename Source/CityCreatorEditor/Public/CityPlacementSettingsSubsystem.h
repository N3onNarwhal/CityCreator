#pragma once

#include "CoreMinimal.h"

#if WITH_EDITOR
#include "EditorSubsystem.h"
#include "CityPlacementSettingsSubsystem.generated.h"

UCLASS()
class CITYCREATOREDITOR_API UCityPlacementSettingsSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "CityPlacement|Settings")
	void SetGridSize(float NewGridSize);

	UFUNCTION(BlueprintCallable, Category = "CityPlacement|Settings")
	float GetGridSize() const;

private:
	UPROPERTY()
	float GridSize = 500.0f;
};
#endif
