// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreInstrumentObject_.h"




UCoreInstrumentObject_::UCoreInstrumentObject_()
{
	IsPossibleToUse = true;
	Stamina_Cost_Per_Use = 10.f;
	InteractTime = 0.5f;
	ReleaseTime = 1.5f;
	SlctIndex = 0;
	EnergyCost = 3;
}

void UCoreInstrumentObject_::UseInstrument(float& Spent_Stamina, float& Spent_Energy, float& Interact_Time, float& Release_Time)
{
	InstrumentUsed();
	Spent_Stamina = Stamina_Cost_Per_Use;
	Spent_Energy = EnergyCost;
	Interact_Time = InteractTime;
	Release_Time  = ReleaseTime;
	OnIstrumentUsed();
}

void UCoreInstrumentObject_::InstrumentUsed()
{
	
}