// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseInstrumentComponent.h"

UBaseInstrumentComponent::UBaseInstrumentComponent()
{
	Stamina_Cost_Per_Use = 10.f;
	Use_Delay = 10.f;
	StaminaCost = Stamina_Cost_Per_Use;
	UseDelay = Use_Delay;
	IsPossibleToUse = true;
			
}


void UBaseInstrumentComponent::BeginPlay()
{
	Super::BeginPlay();
	StaminaCost = Stamina_Cost_Per_Use;
	UseDelay = Use_Delay;
}



void UBaseInstrumentComponent::UseInstrument(float &Spent_Stamina, float & Next_Use_Delay)
{
	if (IsPossibleToUse == true)
	{
		InstrumentUsed();
		Spent_Stamina = StaminaCost;
		Next_Use_Delay = UseDelay;
		OnIstrumentUsed();
	}
	
}

void UBaseInstrumentComponent::InstrumentUsed()
{

}

