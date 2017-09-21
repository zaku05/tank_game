// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank_Fite.h"
#include "CollisionQueryParams.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//Forward declarations
class UTankAimingComponent;
class ATank;

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


protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:

	// ATankPlayerController();

	//Start the tank moving the barrel to that a shot would hit where the crosshair
	// intersects the world
	void AimTowardsCrosshair(); 

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossessedTankDeath();

};
