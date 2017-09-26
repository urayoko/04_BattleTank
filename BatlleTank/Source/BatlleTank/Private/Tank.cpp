// Fill out your copyright notice in the Description page of Project Settings.

#include "BatlleTank.h"
#include "TankBarrel.h"
#include "Tank.h"
#include "Projectile.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();	
}

//
//void ATank::AimAt(FVector HitLocation)
//{
//	if (!ensure(TankAimingComponent)) return;
//	
//	TankAimingComponent->AimAt(HitLocation, this->LauchSpeed);
//	//UE_LOG(LogTemp, Warning, TEXT("I'm here"));
//}

void ATank::Fire()
{
	if (!ensure(Barrel)) return;

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;	
	

	if (isReloaded)
	{

		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f : Tank fires"), Time);

		// Spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
		);

		//Projectile->LaunchProjectile(LauchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}

}

