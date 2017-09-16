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
	Ready
};


// Forward Declaration
class UTankBarrel; 
class UTankTurretSM;


//Holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_FITE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurretSM* TurretToSet);

	virtual void AimAt(FVector HitLocation, float LaunchSpeed);

protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Ready;

private: 
	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;
	
	UTankTurretSM* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

};
