// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankAimingComp.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Runtime/CoreUObject/Public/Templates/Casts.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurrent;
class AProjectile;
class UTankTrack;
class UTankMovementComponent;
UCLASS()
class BATTLETANKVR_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurrent* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = Firing)
		void Fire();
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTrackReference(UTankTrack* TrackToSet);

protected:
	UTankAimingComp* TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBluePrint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 4000; // TODO find sensible default

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloatTimeInSeconds = 3;

	double LastFireTime = 10;

	UTankBarrel* Barrel = nullptr;
	UTankTrack* Track = nullptr;
};