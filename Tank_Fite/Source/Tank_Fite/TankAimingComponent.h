// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Classes/Kismet/GameplayStaticsTypes.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

// enum for aiming state
UENUM()
enum class EFiringState : uint8 
{ 
	Reloading,
	Aiming, 
	Ready,
	NoAmmo
};

// Forward Declaration
class UTankBarrel; 
class UTankTurretSM;
class AProjectile;

//Holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_FITE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurretSM* TurretToSet);

	virtual void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();
	
	bool IsBarrelMoving();

	EFiringState GetFiringState() const;
	
	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetAmmoCount() const;

protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private: 
	
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;
	
	UTankTurretSM* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 5000.0f;

	void MoveBarrelTowards(FVector AimDirection);

	double LastFireTime = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBluePrint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeinSeconds = 3.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 AmmoCount = 5;

	FVector AimDirection;
};
