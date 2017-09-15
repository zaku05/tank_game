// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank_Fite.h"
#include "Tank.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		// TODO move towards player
		AITank->AimAt(PlayerTank->GetActorLocation());

		AITank->Fire(); // TODO dont fire every frame
	}
}


/*ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

/*ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (! PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
} */

