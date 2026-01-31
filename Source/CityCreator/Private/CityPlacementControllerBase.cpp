#include "CityPlacementControllerBase.h"

ACityPlacementControllerBase::ACityPlacementControllerBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACityPlacementControllerBase::OnEditorPlacement_Implementation(FVector WorldPosition)
{
	UE_LOG(LogTemp, Warning, TEXT("C++ OnEditorPlacement_Implementation: %s"), *WorldPosition.ToString());
}
