// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreActionInstruments.h"

UCoreActionInstruments::UCoreActionInstruments()
{
	capacity = 100;
	amount = 10;
	filling = 100;
}

void UCoreActionInstruments::InstrumentUsed()
{
	if (filling > 0)
	{
		filling = filling - amount;
		//if (ToolActor)
			//ToolActor->OnInstrumentUsed(InteractTime);

	}

	else
	{
		IsPossibleToUse = false;
		filling = 0.f;
		OnEmptied();
		
	}
}

void UCoreActionInstruments::Fill()
{
	filling = 100;
	OnFilled();
	IsPossibleToUse = true;

}

void UCoreActionInstruments::SetUsePossibility()
{
	if (filling > 0)
		IsPossibleToUse = true;
	else
		IsPossibleToUse = false;
}