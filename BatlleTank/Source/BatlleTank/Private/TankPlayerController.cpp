// Fill out your copyright notice in the Description page of Project Settings.

#include "BatlleTank.h"
#include "Tank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing : %s"), *ControlledTank->GetName());

	}
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) return;

	FVector HitLocation; // Out parameter

	if (GetSightRayHitLocation(HitLocation)) // Has side-effect , is going to line trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());

		// Tell controlled tank to aim at this point
		GetControlledTank()->AimAt(HitLocation);

	}
}

// Get world location if linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize( ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation : %s"), *ScreenLocation.ToString());

	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
		
		// Line-trace along that look direction, and see what we hit (up to max range)	
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * this->LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}

	HitLocation = FVector(0);
	return false; // Line trace didnt success
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // To be discarded
	
	return DeprojectScreenPositionToWorld( ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);	
	
}