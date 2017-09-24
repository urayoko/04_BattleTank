// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

// Forward Declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATLLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
private:

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;

};
