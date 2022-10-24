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
}


// Called when the game starts
void UCorePlayerStats::BeginPlay()
{
	Super::BeginPlay();

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

	if (bEnergy == true)
	{
		FEnergy(DeltaTime);
	}
}


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

void UCorePlayerStats::FEnergy(float DTime)
{
	fEDelay = fEDelay + DTime;

	if (fEDelay >= 10)
	{
		EnergyReduce(EnergyRate);
		fEDelay = 0.f;
		
	}
}



void UCorePlayerStats::GetEnergy(float& Energy)
{
	Energy = fEnergy;
}

void UCorePlayerStats::EnergyReduce(float EnergyCost)
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
	OnEnergyReduced(fEnergy);
}