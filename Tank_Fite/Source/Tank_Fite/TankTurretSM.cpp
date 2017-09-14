// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurretSM.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"


void UTankTurretSM::TurretRotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto TurretRotation = RelativeRotation.Yaw + RotationChange;
	
	SetRelativeRotation(FRotator(0, TurretRotation, 0));
}
