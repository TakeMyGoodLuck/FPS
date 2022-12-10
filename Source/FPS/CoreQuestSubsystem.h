// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreQuestActor.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CoreQuestSubsystem.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FCurrentQuestStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	ACoreQuestActor* QuestActor;

	UPROPERTY(BlueprintReadWrite)
	int QuestIndex;
	UPROPERTY(BlueprintReadWrite)
	int InteractType;
	

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuestChanged, FText, QuestCaption, FText, QuestDescription);

UCLASS()
class FPS_API UCoreQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()


public:


		UCoreQuestSubsystem();


		virtual void Initialize(FSubsystemCollectionBase& Collection) override;

		
private:

		FCurrentQuestStruct CurrentQuest;

public:

	UFUNCTION(BlueprintCallable)
		void UpdateQuest(ACoreQuestActor* QuestActor, int InteractType);

	UFUNCTION(BlueprintCallable)
		void SetFirstQuest(ACoreQuestActor* QuestActor, int QuestIndex, int InteractType);

	UFUNCTION(BlueprintCallable)
		void CheckQuestActor(ACoreQuestActor* ActorToCheck, bool& Result);
	
	UPROPERTY(BlueprintAssignable)
		FOnQuestChanged OnQuestChanged;

	UFUNCTION(BlueprintPure)
		FCurrentQuestStruct GetCurrentQuest();

};
