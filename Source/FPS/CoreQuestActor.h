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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int AmountToComplete;

	UPROPERTY(BlueprintReadOnly)
		bool Completed;

	UPROPERTY(EditAnywhere)
		bool Hint;

	UPROPERTY(EditAnywhere)
		TArray<FText> HintText;

	UPROPERTY(EditAnywhere, Category = "Tutorial")
		bool Tutorial;

	UPROPERTY(EditAnywhere, Category = "Tutorial")
		FText TutorialName;

	UPROPERTY(EditAnywhere, Category = "Tutorial")
		FText TutorialText;

	FQuestStruct()
	{
		AmountToComplete = 1;
		Hint = false;
		Tutorial = false;
	}

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
