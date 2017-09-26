// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward Declarations
class UTankBarrel; 
class AProjectile;

UCLASS()
class BATLLETANK_API ATank : public APawn
{
	GENERATED_BODY()
		
public:

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;	

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;	

	double LastFireTime = 0;

	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; // TODO remove
};
