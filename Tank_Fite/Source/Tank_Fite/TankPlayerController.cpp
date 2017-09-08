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

	UE_LOG(LogTemp, Warning, TEXT("Tick."));	
	
} 

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	//get world location if line trace through crosshair
	// if it hits the landscape
		//then we want the controlled tank to aim at this point
}