// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreWorldTimeManager.h"
#include "CoreGameInstance.h"

// Sets default values
ACoreWorldTimeManager::ACoreWorldTimeManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TimeSpeed = 1.f;

}

// Called when the game starts or when spawned
void ACoreWorldTimeManager::BeginPlay()
{
	Super::BeginPlay();
	Timer();
	
	
}

// Called every frame
void ACoreWorldTimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoreWorldTimeManager::Timer()
{
	GetWorldTimerManager().SetTimer(WorldTimerHandle, this, &ACoreWorldTimeManager::SetTime, TimeSpeed, true);
	
	
}

void ACoreWorldTimeManager::SetTime()
{
	UCoreGameInstance* GI = Cast<UCoreGameInstance>(GetGameInstance());
	GI->FIncrementTime();
}

