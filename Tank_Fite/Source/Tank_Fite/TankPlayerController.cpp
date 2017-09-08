// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank_Fite.h"


/* ATankPlayerController::ATankPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}
*/
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Controller for tank found!"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is controlling %s"), *(ControlledTank->GetName()))
	}
}

void ATankPlayerController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	AimTowardsCrosshair();
	
} 

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation; // Out parameter
	if (GetSightRayHitLocation(OutHitLocation)) // has "side effect" of ray tracing
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString());

			//then we want the controlled tank to aim at this point
	}
}

//get world location of line trace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0); // OutParameter

	return false;
}