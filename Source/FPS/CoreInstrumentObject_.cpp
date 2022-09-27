// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreInstrumentObject_.h"

UCoreInstrumentObject_::UCoreInstrumentObject_()
{
	IsPossibleToUse = true;
	Stamina_Cost_Per_Use = 10.f;
	Use_Delay = 1.f;
}

void UCoreInstrumentObject_::UseInstrument(float& Spent_Stamina, float& Next_Use_Delay)
{
	InstrumentUsed();
	Spent_Stamina = Stamina_Cost_Per_Use;
	Next_Use_Delay = Use_Delay;
	OnIstrumentUsed();
}

void UCoreInstrumentObject_::InstrumentUsed()
{

}