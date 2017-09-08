// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank_Fite.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Controller for enemy tank found!"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller is controlling %s"), *(ControlledTank->GetName()))
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No player tank found."))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player is controlling %s"), *(PlayerTank->GetName()))
	}

}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

