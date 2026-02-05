#include "CityPlacementSettingsSubsystem.h"

void UCityPlacementSettingsSubsystem::SetGridSize(float NewGridSize)
{
	GridSize = FMath::Max(1.0f, NewGridSize);

	UE_LOG(LogTemp, Warning, TEXT("CityPlacement GridSize = %f"), GridSize);
}

float UCityPlacementSettingsSubsystem::GetGridSize() const
{
	return GridSize;
}
