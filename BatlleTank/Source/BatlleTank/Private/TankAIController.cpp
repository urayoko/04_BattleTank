// Fill out your copyright notice in the Description page of Project Settings.

#include "BatlleTank.h"
#include "TankAIController.h"
#include "Tank.h" // put here by purpose




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

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank))
	{
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready
		ControlledTank->Fire(); // TODO limit firing rate
	}
}

