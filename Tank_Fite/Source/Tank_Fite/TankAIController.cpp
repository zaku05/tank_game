// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank_Fite.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller cant find player tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI reports player is controlling %s"), *(PlayerTank->GetName()));
	}

}

void ATankAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	if (GetPlayerTank())
	{
		// TODO move towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation()); // aim at player
		// fire

		// AimTowardsCrosshair();
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (! PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

