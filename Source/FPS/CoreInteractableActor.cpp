// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreInteractableActor.h"


// Sets default values
ACoreInteractableActor::ACoreInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SceneComponent->SetupAttachment(RootComponent);


	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(SceneComponent);


}

// Called when the game starts or when spawned
void ACoreInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoreInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoreInteractableActor::Interact_Implementation(UCoreInstrumentObject_* Instrument, bool& Success)
{
	
}


void ACoreInteractableActor::CInteract(UCoreInstrumentObject_* Instrument, bool& Success)
{

}
