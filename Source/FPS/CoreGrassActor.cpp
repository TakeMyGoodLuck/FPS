// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreGrassActor.h"

ACoreGrassActor::ACoreGrassActor()
{
	PrimaryActorTick.bCanEverTick = false;

	GrowthSpd = 1.f;
	GrAccel = 1.f;
	GrSpeed = GrowthSpd;
	GrAcclr = GrAccel;
	IsMaxState = false;
	State = 0;

}

void ACoreGrassActor::BeginPlay()
{
	GrSpeed = GrowthSpd;
	GrAcclr = GrAccel;
	State = 0;
	GrowGrass(IsMaxState);
	Super::BeginPlay();
}

void ACoreGrassActor::SetGrthSpd(float Speed)
{
	GrSpeed = Speed;
}

void ACoreGrassActor::SetGrthAccel(float Acceleration)
{
	GrAcclr = Acceleration;
}

void ACoreGrassActor::GetGrthSpd(float& Speed)
{
	Speed = GrSpeed * GrAcclr;
}

void ACoreGrassActor::GetGrthAccel(float& Acceleration)
{
	Acceleration = GrAcclr;
}

void ACoreGrassActor::GetState(int& GrowthState)
{
	GrowthState = State;
}

void ACoreGrassActor::GrowGrass(bool &IsMax)
{
	if (IsMaxState == false)
	{
		switch (State)
		{
		case (0):
			SetActorRelativeScale3D(FVector(1.f, 1.f, 0.33f));
			State++;
			IsMax = IsMaxState;
			break;
		case (1):
			SetActorRelativeScale3D(FVector(1.f, 1.f, 0.66f));
			State++;
			IsMax = IsMaxState;
			break;
		case (2):
			SetActorRelativeScale3D(FVector(1.f, 1.f, 1.f));
			IsMaxState = true;
			IsMax = IsMaxState;
		};
		OnGrassGrowed();
	}
	
}

void ACoreGrassActor::Reset()
{
	State = 0;
	IsMaxState = false;
	GrowGrass(IsMaxState);
}

