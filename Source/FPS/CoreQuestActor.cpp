// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreQuestActor.h"

// Sets default values
ACoreQuestActor::ACoreQuestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SceneComponent->SetupAttachment(RootComponent);


	Pointer = CreateDefaultSubobject<UWidgetComponent>(TEXT("Pointer"));
	Pointer->SetupAttachment(SceneComponent);

	static ConstructorHelpers::FClassFinder<UUserWidget>WidgetClassFinder(TEXT("/Game/Blueprints/WidgetBlueprints/WBP_Pointer"));
	Pointer->SetWidgetClass(WidgetClassFinder.Class);
	Pointer->SetDrawAtDesiredSize(true);
	Pointer->SetWidgetSpace(EWidgetSpace::Screen);
	Pointer->SetVisibility(false);

}

// Called when the game starts or when spawned
void ACoreQuestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoreQuestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

