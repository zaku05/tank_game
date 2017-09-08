// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank_Fite.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */

UCLASS()
class TANK_FITE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public: 
	// ATankPlayerController();

	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float Deltatime) override;

	//Start the tank moving the barrel to that a shot would hit where the crosshair
	// intersects the world
	void AimTowardsCrosshair(); 

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
