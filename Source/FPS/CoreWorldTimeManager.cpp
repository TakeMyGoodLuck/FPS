// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreWorldTimeManager.h"



// Sets default values
ACoreWorldTimeManager::ACoreWorldTimeManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TimeSpeed = 1.f;
	TimerSpd = 1.f;
	TimeRate = 12.f;
}

// Called when the game starts or when spawned
void ACoreWorldTimeManager::BeginPlay()
{
	Super::BeginPlay();
	CalculateTime();
	GI = Cast<UCoreGameInstance>(GetGameInstance());
	SetGITimeSpeed();
	Timer();
	
	
}

// Called every frame
void ACoreWorldTimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ACoreWorldTimeManager::Timer()
{
	GetWorldTimerManager().SetTimer(WorldTimerHandle, this, &ACoreWorldTimeManager::SetTime, 1/TimerSpd, true);
	
	
}

void ACoreWorldTimeManager::SetTime()
{
	GI->FIncrementTime(TimeSpeed);
	float X;
	GI->GetTimerSpeed(X);
	if (X != TimerSpd)
	{
		TimerSpd = X;
		GI->SetTimerSpeed(TimerSpd);
		Timer();
	}

	
	float Minute = static_cast<float>((GI->STime.Hours * 60) + (GI->STime.Minutes));
	UpdateSunPosition(Minute);
	
}

void ACoreWorldTimeManager::SetGITimeSpeed()
{
	GI->SetTimerSpeed(TimerSpd);
	GI->SetTimeSpeed(TimeSpeed);
}

void ACoreWorldTimeManager::UpdateSunPosition(float Minutes)
{
	if (LightSource)
	{
		LightSource->SetActorRelativeRotation(FRotator(Minutes*0.25+90, 0, 0));
	}
	if (Sun)
	{
		
		Sun->CallFunctionByNameWithArguments(TEXT("UpdateSunDirection"), ar, NULL, true);

		
	}
}

void ACoreWorldTimeManager::GetTSPD(float& SPD)
{
	SPD = TimeSpeed;
}

void ACoreWorldTimeManager::CalculateTime()
{
	TimeSpeed = 86400 / TimeRate / 3600;
}