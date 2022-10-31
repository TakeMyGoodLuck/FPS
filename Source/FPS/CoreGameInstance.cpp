// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreGameInstance.h"

UCoreGameInstance::UCoreGameInstance()
{

}

void UCoreGameInstance::FIncrementTime()
{
	STime.IncrementTime();
}

void UCoreGameInstance::GetTime(FTimeStruct& Time)
{
	Time = STime;
}

