// Fill out your copyright notice in the Description page of Project Settings.


#include "CorePlayerStats.h"

// Sets default values for this component's properties
UCorePlayerStats::UCorePlayerStats()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	DefWait = 2.f;
	MaxWait = 4.f;
	fStamina = 1.f;
	fWait = DefWait;
	bRestore = false;
	bDelay = false;
	x = 0.f;
	bEnergy = true;
	fEDelay = 0.f;
	fEnergy = 1.f;
	EnergyRate = 3.f;
	fEnergyTimerSpd = 1.f;
	fHungry = 1.f;
	HungryRate = 2.f;
	HungryLow = 20.f;
	fThirst = 1.f;
	ThirstRate = 7.f;
	ThirstLow = 20.f;

	SleepDuration = 5.f;
	EnergyRecover = 5.f;
	bSleeping = false;

	fHeat = 0.f;
	HeatingUp = 0.3f;
	Cooling = 1.f;
	bHeatingUp = false;
	bOverheat = false;
}


// Called when the game starts
void UCorePlayerStats::BeginPlay()
{
	Super::BeginPlay();


	if (TimeManager != NULL)
	{
		

		fTimeSpeed = TimeManager->TimeSpeed;

		

		
		FEnergyTimer(60 / fTimeSpeed);
		FHungryTimer(60 / fTimeSpeed);
		FThirstTimer(60 / fTimeSpeed);
		
		// ...
	}
}




// Called every frame
void UCorePlayerStats::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (bDelay == true)
	{
		FDelay(DeltaTime);
	}

	if (bRestore == true) 
	{
		FRestore();
	}


}


//Stmina

void UCorePlayerStats::StaminaReduce(float StaminaCost)
{
	
	

	fStamina = fStamina - (StaminaCost / 100);
	x = 0.f;
	bRestore = false;
	
	
	if (fStamina <= 0)
	{
		fStamina = 0.f;
		fWait = MaxWait;
		
	}
	else
	{
		fWait = DefWait;
	}

	bDelay = true;
	OnStaminaReduced(fStamina);
}

void UCorePlayerStats::FRestore()
{
	
	if (fStamina > 0.333)
	{
		fStamina = fStamina + 0.003;
	}
	else
	{
		fStamina = fStamina + 0.001;
	}

	if (fStamina >= 1)
	{
		bRestore = false;
		fStamina = 1;
	}

	OnStaminaRestoring(fStamina);
}

void UCorePlayerStats::GetStamina(float& Stamina)
{
	Stamina = fStamina;
}

void UCorePlayerStats::FDelay(float DTime)
{
	x = x + DTime;
	if (x >= fWait)
	{

		bDelay = false;
		bRestore = true;
	}

}



//Energy


void UCorePlayerStats::GetEnergy(float& Energy)
{
	Energy = fEnergy;
}

void UCorePlayerStats::ReduceEnergy(float EnergyCost)
{
	fEnergy = fEnergy - (EnergyCost / 100);

	if (fEnergy <= 0)
	{
		fEnergy = 0;
		bEnergy = false;
	}

	OnEnergy(fEnergy);
	
	
}

void UCorePlayerStats::EnergyRestore()
{
	fEnergy = 1.f;
	GetWorld()->GetTimerManager().ClearTimer(EnergyTimerHandle);
	FEnergyTimer(60 / fTimeSpeed);
	OnEnergy(fEnergy);
}



void UCorePlayerStats::FEnergyTimer(float Time)
{
	GetWorld()->GetTimerManager().SetTimer(EnergyTimerHandle, this, &UCorePlayerStats::FReduceEnergy, Time, false);
}

void UCorePlayerStats::FReduceEnergy()
{
	fEnergy = fEnergy - (EnergyRate/100);
	
	

	if (fEnergy <= 0)
	{
		fEnergy = 0;
		GetWorld()->GetTimerManager().ClearTimer(EnergyTimerHandle);
	}

	else
	{
		FEnergyTimer(60 / fTimeSpeed);
	}

	OnEnergy(fEnergy);
}







//Hungry

void UCorePlayerStats::FHungryDecrease()
{
	fHungry = fHungry - (HungryRate/100);
	if (fHungry <= HungryLow/100 && bHungryLow == false)
	{
		bHungryLow = true;
		OnHungryLow(fHungry);
	}

	if (fHungry <= 0)
	{
		fHungry = 0;
		GetWorld()->GetTimerManager().ClearTimer(HungryHandle);
		OnHungryMax();

		if (bSleeping == true)
		{
			FEndSleep();
			WakeOnHunger();
		}

	}
	else
	{
		
		
		
		
		FHungryTimer(60 / fTimeSpeed);
	}

	OnHungry(fHungry);
}

void UCorePlayerStats::FeedHungry(float FoodValue)
{
	if (bSleeping == false)
	{
		fHungry = fHungry + (FoodValue / 100);
		if (fHungry > HungryLow / 100 && bHungryLow == true)
		{
			bHungryLow = false;
		}

		if (fHungry >= 1.f)
		{
			fHungry = 1.f;
		}


		FHungryTimer(60 / fTimeSpeed);

		OnHungry(fHungry);
	}
}

void UCorePlayerStats::FHungryTimer(float Time)
{
	GetWorld()->GetTimerManager().SetTimer(HungryHandle, this, &UCorePlayerStats::FHungryDecrease, Time, false);
}


//Thirst

void UCorePlayerStats::FThirstDecrease()
{
	fThirst = fThirst - (ThirstRate / 100);
	if (fThirst <= ThirstLow / 100 && bThirstLow == false)
	{
		bThirstLow = true;
		OnThirstLow(fThirst);
	}

	if (fThirst <= 0)
	{
		fThirst = 0;
		GetWorld()->GetTimerManager().ClearTimer(ThirstHandle);
		OnThirstMax();
		if (bSleeping == true)
		{
			FEndSleep();
			WakeOnThirst();
		}

	}
	else
	{
		
		FThirstTimer(60 / fTimeSpeed);
	}

	OnThirst(fThirst);
}

void UCorePlayerStats::FThirstTimer(float Time)
{
	GetWorld()->GetTimerManager().SetTimer(ThirstHandle, this, &UCorePlayerStats::FThirstDecrease, Time, false);
}

void UCorePlayerStats::FeedThirst(float DrinkValue)
{
	if (bSleeping == false)
	{
		fThirst = fThirst + (DrinkValue / 100);
		if (fThirst > ThirstLow / 100 && bThirstLow == true)
		{
			bThirstLow = false;
		}

		if (fThirst >= 1.f)
		{
			fThirst = 1.f;
		}


		FThirstTimer(60 / fTimeSpeed);


		OnThirst(fThirst);
	}
}


//Sleeping

void UCorePlayerStats::Sleep(float SleepTime)
{
	if (fHungry <= 0 || fThirst <= 0)
	{
		if (fHungry <= 0)
		{
			WakeOnHunger();
		}

		if (fThirst <= 0)
		{
			WakeOnThirst();
		}

	}

	else
	{
		
		bSleeping = true;
		GetWorld()->GetTimerManager().ClearTimer(EnergyTimerHandle);

		fTimeSpeed = 60 * SleepTime / SleepDuration;
		FSleepTimer(SleepDuration);
		TimeManager->TimeSpeed = fTimeSpeed;
		FHungryTimer(60 / fTimeSpeed);
		FThirstTimer(60 / fTimeSpeed);
		FEnergyRestoreTimer(60 / fTimeSpeed);
		FTemperatureTimer(1 / fTimeSpeed);
	}
	
}

void UCorePlayerStats::FSleepTimer(float Time)
{
	GetWorld()->GetTimerManager().SetTimer(DelayHandle, this, &UCorePlayerStats::FEndSleep, Time, false);
}

void UCorePlayerStats::FEndSleep()
{
	bSleeping = false;
	GetWorld()->GetTimerManager().ClearTimer(EnergyRestoreHandle);

	TimeManager->CalculateTime();
	fTimeSpeed = TimeManager->TimeSpeed;
	FEnergyTimer(60 / fTimeSpeed);
	FHungryTimer(60 / fTimeSpeed);
	FThirstTimer(60 / fTimeSpeed);
	FTemperatureTimer(1 / fTimeSpeed);
	

}


void UCorePlayerStats::FEnergyRestoreTimer(float Time)
{
	GetWorld()->GetTimerManager().SetTimer(EnergyRestoreHandle, this, &UCorePlayerStats::FEnergyRestore, Time, false);
}

void UCorePlayerStats::FEnergyRestore()
{
	fEnergy = fEnergy + (EnergyRecover / 100);

	if (fEnergy >= 1)
	{
		fEnergy = 1.f;
		GetWorld()->GetTimerManager().ClearTimer(EnergyRestoreHandle);
	}
	else
	{
		FEnergyRestoreTimer(60 / fTimeSpeed);
	}



	OnEnergy(fEnergy);

}




void UCorePlayerStats::FTemperatureTimer(float Time)
{
	GetWorld()->GetTimerManager().SetTimer(TemperaturHandle, this, &UCorePlayerStats::FTemperature, Time, true);
}

void UCorePlayerStats::FTemperature()
{
	if (bHeatingUp)
	{
		fHeat = fHeat + (HeatingUp / 100);
		if (fHeat >= 1)
		{
			fHeat = 1;
			if (!bOverheat)
			{
				bOverheat = true;
				GetWorld()->GetTimerManager().SetTimer(OverheatHandle, this, &UCorePlayerStats::FOverheat, 5.f, false);
			}
			
		}

	}

	else
	{
		fHeat = fHeat - (Cooling / 100);
		if (fHeat <= 0)
		{
			fHeat = 0;
		}
		if (bOverheat)
		{
			bOverheat = false;
			GetWorld()->GetTimerManager().ClearTimer(OverheatHandle);
		}

	}

	OnTemperatureUpdated(fHeat);
}

void UCorePlayerStats::SetHeatingState(bool Heating)
{
	GetWorld()->GetTimerManager().ClearTimer(TemperaturHandle);
	bHeatingUp = Heating;
	FTemperatureTimer(1 / fTimeSpeed);


}

void UCorePlayerStats::FOverheat()
{
	
	fEnergy = 0.01f;
	OnEnergy(fEnergy);
	fThirst = 0.01f;
	OnThirst(fThirst);
	fHungry = 0.01f;
	OnHungry(fHungry);

	OnOverheat();


}