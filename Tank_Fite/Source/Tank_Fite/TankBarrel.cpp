// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	// rotate the barrel to match aim direction
	// limit the speed of the barrel so it can't instantly snap to the aim direction

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1); // this line mutates instead of having to use a new variable!
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinDegreesElevation, MaxDegreesElevation);

	// FMath::Clamp<float>(RawNewElevation, MinDegreesElevation, MaxDegreesElevation);

	SetRelativeRotation(FRotator(Elevation, 0, 0));


}

