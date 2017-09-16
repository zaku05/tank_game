// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel; // Forward Declaration
class UTankAimingComponent;
class UTankTurretSM;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class TANK_FITE_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

public:

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBluePrint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeinSeconds = 3.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 5000.0f; 

	UTankBarrel* Barrel = nullptr; // TODO remove

	double LastFireTime = 0;
};
