// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank_Fite.h"
#include "AIController.h"
#include "TankAIController.generated.h"

//Forward declarations
class UTankAimingComponent;
class ATank;
/**
 * 
 */

UCLASS()
class TANK_FITE_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	virtual void Tick(float Deltatime) override;
	
	virtual void BeginPlay() override;

private:

	// ATank* GetControlledTank() const;

	// ATank* GetPlayerTank() const;

};
