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

void UCoreInstrumentObject_::UseInstrument(ACoreInteractableActor* Interacted_Actor, bool& Success, float& Stamina_Cost, float& Energy_Cost, float& Interact_Time, float& Release_Time)
{
	if (IsPossibleToUse == true)
	{
		Interacted_Actor->Interact(this, Success);
		if (Success == true)
		{
			InstrumentUsed();
			Stamina_Cost = Stamina_Cost_Per_Use;
			Energy_Cost = EnergyCost;
			Interact_Time = InteractTime;
			Release_Time = ReleaseTime;
			OnIstrumentUsed();
		}

		
	}
	else
		Success = false;
}

void UCoreInstrumentObject_::InstrumentUsed()
{
	
}