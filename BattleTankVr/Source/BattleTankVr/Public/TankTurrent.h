// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurrent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANKVR_API UTankTurrent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 max downward speed and +1 is max up movement
	void Rotate(float RelavativeSpeed);

private:
	UPROPERTY(EditAnywhere)
		float MaxDegreesPerSecond = 20;

};
