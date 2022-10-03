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
		filling = filling - amount;
	else
		OnEmptied();

}

void UCoreActionInstruments::Fill()
{
	filling = 100;
	OnFilled();

}