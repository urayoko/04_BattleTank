// Fill out your copyright notice in the Description page of Project Settings.

#include "BatlleTank.h"
#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	// TODO clamp actual throttle value so player cant over drive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

