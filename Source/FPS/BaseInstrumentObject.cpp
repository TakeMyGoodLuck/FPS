// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseInstrumentObject.h"



// Sets default values
ABaseInstrumentObject::ABaseInstrumentObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	Mesh->SetupAttachment(RootComponent);

	StaminaCostPerUse = 0.5f;

	UseDelay = 0.5f;



	
	
}

// Called when the game starts or when spawned
void ABaseInstrumentObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseInstrumentObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

void ABaseInstrumentObject::OnInstrumentUsed(float &StaminaCost, float &NextUseDelay)
{
	StaminaCost = StaminaCostPerUse;
	NextUseDelay = UseDelay;
	InstrumentUsed();
}





