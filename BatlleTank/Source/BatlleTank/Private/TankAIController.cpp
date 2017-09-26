// Fill out your copyright notice in the Description page of Project Settings.

#include "BatlleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"





void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	//auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	//if (!PlayerTank)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));

	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AIController found player : %s"), *PlayerTank->GetName());

	//}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) return;
	
	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

	// Aim towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// TODO fix firing
	// Fire if ready
	//ControlledTank->Fire(); // TODO limit firing rate
	
}

