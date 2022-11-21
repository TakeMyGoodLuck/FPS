// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreQuestActor.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CoreQuestSubsystem.generated.h"

/**
 * 
 */
struct CurrentQuestStruct
{

	ACoreQuestActor* QuestActor;

	int QuestIndex;
	

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestChanged, FText, QuestDescription);

UCLASS()
class FPS_API UCoreQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()


public:


		UCoreQuestSubsystem();


		virtual void Initialize(FSubsystemCollectionBase& Collection) override;

		
private:

		CurrentQuestStruct CurrentQuest;

public:

	UFUNCTION(BlueprintCallable)
		void UpdateQuest(ACoreQuestActor* QuestActor);

	UFUNCTION(BlueprintCallable)
		void SetFirstQuest(ACoreQuestActor* QuestActor, int QuestIndex);

	
	UPROPERTY(BlueprintAssignable)
		FOnQuestChanged OnQuestChanged;


};
