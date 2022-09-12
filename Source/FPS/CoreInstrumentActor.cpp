// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreInstrumentActor.h"

// Sets default values
ABaseInstrumentActor::ABaseInstrumentActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	Stamina_Cost_Per_Use = 10.f;
	Use_Delay = 1.f;
	StaminaCost = Stamina_Cost_Per_Use;
	UseDelay = Use_Delay;
	IsPossibleToUse = true;
	QAImage = 0;

}

// Called when the game starts or when spawned
void ABaseInstrumentActor::BeginPlay()
{
	Super::BeginPlay();
	StaminaCost = Stamina_Cost_Per_Use;
	UseDelay = Use_Delay;
	
}

// Called every frame
void ABaseInstrumentActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseInstrumentActor::UseInstrument(AActor* Interacted_Actor, float& Spent_Stamina, float& Next_Use_Delay)
{
	if (IsPossibleToUse == true)
	{
		InstrumentUsed();
		Spent_Stamina = StaminaCost;
		Next_Use_Delay = UseDelay;
		OnIstrumentUsed(Interacted_Actor);
	}

}

void ABaseInstrumentActor::InstrumentUsed()
{

}