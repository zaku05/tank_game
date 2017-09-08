// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank_Fite.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */

UCLASS()
class TANK_FITE_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	ATank* GetControlledTank() const;

	void BeginPlay() override;
};
