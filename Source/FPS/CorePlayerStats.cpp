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
}


// Called when the game starts
void UCorePlayerStats::BeginPlay()
{
	Super::BeginPlay();
	
	GI = Cast<UCoreGameInstance>(GetWorld()->GetGameInstance());
	float z;
	GI->GetTimeSpeed(z);
	fEnergyTimerSpd = 60 / z;
	FEnergyTimer();
	FHungryTimer(60 / z);
	FThirstTimer(60 / z);
	// ...
	
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

void UCorePlayerStats::FEnergy(float DTime)
{
	fEDelay = fEDelay + DTime;

	if (fEDelay >= 10)
	{
		ReduceEnergy(EnergyRate);
		fEDelay = 0.f;
		
	}
}



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

	OnEnergyReduced(fEnergy);
	
	
}

void UCorePlayerStats::EnergyRestore()
{
	fEnergy = 1.f;
	GetWorld()->GetTimerManager().ClearTimer(EnergyTimerHandle);
	FEnergyTimer();
	OnEnergyReduced(fEnergy);
}

void UCorePlayerStats::Sleep()
{
	GI->SetTimerSpeed(25);
	GetWorld()->GetTimerManager().ClearTimer(EnergyTimerHandle);
	FDelayTimer(2 * 60 / 25);
	float z;
	GI->GetTimerSpeed(z);
	FHungryTimer(60 / z / 25);
	FThirstTimer(60 / z / 25);
}

void UCorePlayerStats::FEnergyTimer()
{
	GetWorld()->GetTimerManager().SetTimer(EnergyTimerHandle, this, &UCorePlayerStats::FReduceEnergy, fEnergyTimerSpd, false);
}

void UCorePlayerStats::FReduceEnergy()
{
	fEnergy = fEnergy - (EnergyRate/100);
	
	FEnergyTimer();

	if (fEnergy <= 0)
	{
		fEnergy = 0;
		GetWorld()->GetTimerManager().ClearTimer(EnergyTimerHandle);
	}
	OnEnergyReduced(fEnergy);
}


void UCorePlayerStats::FDelayTimer(float Time)
{
	GetWorld()->GetTimerManager().SetTimer(DelayHandle, this, &UCorePlayerStats::FEndSleep, Time, false);
}

void UCorePlayerStats::FEndSleep()
{
	GI->SetTimerSpeed(1.f);
	float z;
	GI->GetTimeSpeed(z);
	fEnergy = 1.f;
	OnEnergyReduced(fEnergy);
	FHungryTimer(60 / z);
	FThirstTimer(60 / z);

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

	}
	else
	{
		float z, y;
		GI->GetTimerSpeed(y);
		GI->GetTimeSpeed(z);
		z = 60 / z / y;
		FHungryTimer(z);
	}

	OnHungry(fHungry);
}

void UCorePlayerStats::FeedHungry(float FoodValue)
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

	float z, y;
	GI->GetTimerSpeed(y);
	GI->GetTimeSpeed(z);
	z = 60 / z / y;
	FHungryTimer(z);

	OnHungry(fHungry);
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
		OnHungryLow(fThirst);
	}

	if (fThirst <= 0)
	{
		fThirst = 0;
		GetWorld()->GetTimerManager().ClearTimer(ThirstHandle);
		OnThirstMax();

	}
	else
	{
		float z, y;
		GI->GetTimerSpeed(y);
		GI->GetTimeSpeed(z);
		z = 60 / z / y;
		FThirstTimer(z);
	}

	OnThirst(fThirst);
}

void UCorePlayerStats::FThirstTimer(float Time)
{
	GetWorld()->GetTimerManager().SetTimer(ThirstHandle, this, &UCorePlayerStats::FThirstDecrease, Time, false);
}

void UCorePlayerStats::FeedThirst(float DrinkValue)
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

	float z, y;
	GI->GetTimerSpeed(y);
	GI->GetTimeSpeed(z);
	z = 60 / z / y;
	FThirstTimer(z);
	

	OnThirst(fThirst);
}