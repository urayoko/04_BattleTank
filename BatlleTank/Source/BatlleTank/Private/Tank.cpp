// Fill out your copyright notice in the Description page of Project Settings.

#include "BatlleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// No need to protect points as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, this->LauchSpeed);
	/*auto OurTankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at : %s"), *OurTankName, *HitLocation.ToString());*/
}

void ATank::Fire()
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f : Tank fires"), Time);
}
