// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANKVR_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 max downward speed and +1 is max up movement
	void Elevate(float RelavativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly)
	float MaxDegreesPerSecond = 20;

	UPROPERTY(EditDefaultsOnly)
	float MaxElevationDegrees = 80;
	UPROPERTY(EditDefaultsOnly)
	float MinElevationDegrees = -10;
};
