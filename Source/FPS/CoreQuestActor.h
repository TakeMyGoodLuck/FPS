// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Actor.h"
#include "CoreQuestActor.generated.h"

USTRUCT(BlueprintType)
struct FQuestStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText QuestCaption;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText QuestDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		ACoreQuestActor* NextQuestActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int ActorNextTaskIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int NextActorInteractType;

	UPROPERTY(BlueprintReadOnly)
		bool Completed;



};

UCLASS()
class FPS_API ACoreQuestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoreQuestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UWidgetComponent* Pointer;

	UPROPERTY(EditAnywhere, Category = "Quest")
		TArray<FQuestStruct> Quests;

	int QuestIndex;


};
