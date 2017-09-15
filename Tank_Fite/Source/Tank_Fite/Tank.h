// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel; // Forward Declaration
class UTankAimingComponent;
class UTankTurretSM;
class AProjectile;

UCLASS()
class TANK_FITE_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurretSM* TurretToSet);

	UFUNCTION(BlueprintCallable)
	void Fire();

private:
	UPROPERTY(EditAnyWhere, Category = Firing)
	float LaunchSpeed = 5000.0f; 

	UPROPERTY(EditAnyWhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBluePrint;

	UTankBarrel* Barrel = nullptr;

	float ReloadTimeinSeconds = 3.0f;

	double LastFireTime = 0;
};
