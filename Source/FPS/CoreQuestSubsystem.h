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
	
	UPROPERTY(BlueprintReadWrite)
		int CurrentAmount;

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnQuestChanged, FText, QuestCaption, FText, QuestDescription, int, AmountToComplete, int, CurrentAmount);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQuestCompleted);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FShowHint, FText, BodyText, FText, IntText);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHideHint);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FShowTutorial, FText, Name, FText, Text);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FShowDialog, FText, Text);

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

	UPROPERTY(BlueprintAssignable)
		FOnQuestCompleted OnQuestCompleted;

	UPROPERTY(BlueprintAssignable)
		FShowHint CallHint;

	UPROPERTY(BlueprintAssignable)
		FHideHint CallHideHint;

	UPROPERTY(BlueprintAssignable)
		FShowTutorial ShowTutorial;

	UPROPERTY(BlueprintAssignable)
		FShowDialog CallDialog;

	UFUNCTION(BlueprintPure)
		FCurrentQuestStruct GetCurrentQuest();

	ACoreQuestActor* QuestHolder;

	UFUNCTION(BlueprintCallable)
		void SetQuestHolder(ACoreQuestActor* Actor);

	UFUNCTION(BlueprintPure)
		ACoreQuestActor* GetQuestHolder();

	UFUNCTION(BlueprintCallable)
		void ShowHint(FText Body, FText InText);

	UFUNCTION(BlueprintCallable)
		void HideHint();

	UFUNCTION(BlueprintCallable)
		void ShowDialog(FText Dialog);
};
