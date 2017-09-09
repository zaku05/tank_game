// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank_Fite.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "CollisionQueryParams.h"
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

	virtual void BeginPlay() override;

	virtual void Tick(float Deltatime) override;

private:

	// ATankPlayerController();

	ATank* GetControlledTank() const;

	//Start the tank moving the barrel to that a shot would hit where the crosshair
	// intersects the world
	void AimTowardsCrosshair(); 

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;



};
