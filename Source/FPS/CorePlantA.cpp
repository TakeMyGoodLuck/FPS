// Fill out your copyright notice in the Description page of Project Settings.


#include "CorePlantA.h"


ACorePlantA::ACorePlantA()
{
	GrowthSpd = 10.f;
	GrAccel = 1.f;
	SeedsAmount = 5.f;
	HarvestPerSeed = 10.f;
	MaxStates = 3;

}

void ACorePlantA::GetSpd(float& Growth_Speed)
{
	Growth_Speed = GrowthSpd * GrAccel;

}

void ACorePlantA::GetState(int& Growth_State)
{
	Growth_State = State;
}

void ACorePlantA::GrowPlant()
{
	if (State < MaxStates)
	{
		State++;
		OnPlantGrowed(State);
	}
	
}