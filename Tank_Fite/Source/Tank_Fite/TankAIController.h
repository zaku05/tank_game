// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank_Fite.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/GameFramework/Pawn.h"
#include "TankAIController.generated.h"

//Forward declarations
class UTankAimingComponent;
class UTank;

/**
 * 
 */

UCLASS()
class TANK_FITE_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000.0f;

private:
	virtual void Tick(float Deltatime) override;
	
	virtual void BeginPlay() override;
	
	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossessedTankDeath();

};
