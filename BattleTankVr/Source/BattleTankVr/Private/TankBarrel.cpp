// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "BattleTankVr.h"

void UTankBarrel::Elevate(float RelavativeSpeed) {
	RelavativeSpeed = FMath::Clamp<float>(RelavativeSpeed, -1, 1);
	auto ElevationChange = RelavativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}



