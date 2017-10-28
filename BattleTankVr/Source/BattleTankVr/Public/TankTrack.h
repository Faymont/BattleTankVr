// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTank is used to set maximum dribing force
 */
UCLASS(meta = (BlueprintSpawnableComponent)) //hidecategories = ("Collision"))
class BATTLETANKVR_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	// Max force in Newtons
	UPROPERTY(EditDefaultsOnly, Category = Drive)
		float TrackMaxDrivingForce = 400000; //Assume 40 tank, and 1g acceleration
};
