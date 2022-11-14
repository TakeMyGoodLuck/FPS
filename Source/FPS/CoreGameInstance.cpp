// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreGameInstance.h"

UCoreGameInstance::UCoreGameInstance()
{
	TimerSpd = 1.f;
}



void UCoreGameInstance::FIncrementTime(float AddMinutes)
{
	
}



void UCoreGameInstance::GetTimerSpeed(float& TimerSpeed)
{
	TimerSpeed = TimerSpd;
}

void UCoreGameInstance::SetTimerSpeed(float TimerSpeed)
{
	TimerSpd = TimerSpeed;

	
}

void UCoreGameInstance::SetTimeSpeed(float TimeSpeed)
{
	TimeSpd = TimeSpeed;
}

void UCoreGameInstance::GetTimeSpeed(float& TimeSpeed)
{
	TimeSpeed = TimeSpd;
}

