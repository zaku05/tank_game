// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Classes/Kismet/GameplayStaticsTypes.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"
// Forward Declaration
class UTankBarrel; 
class UTankTurretSM;


//Holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_FITE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTankTurretSM* TurretToSet);


protected:

public:	
	virtual void AimAt(FVector HitLocation, float LaunchSpeed);

private: 
	UTankBarrel* Barrel = nullptr;
	
	UTankTurretSM* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
