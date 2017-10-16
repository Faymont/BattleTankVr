// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurrent.h"
#include "BattleTankVr.h"

void UTankTurrent::Rotate(float RelavativeSpeed) {
	RelavativeSpeed = FMath::Clamp<float>(RelavativeSpeed, -1, 1);
	auto RotateChange = RelavativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotate = RelativeRotation.Yaw + RotateChange;
	SetRelativeRotation(FRotator(0, RawNewRotate, 0));
}


