// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreQuestSubsystem.h"




UCoreQuestSubsystem::UCoreQuestSubsystem()
{

}

void UCoreQuestSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{

	
}

void UCoreQuestSubsystem::UpdateQuest(ACoreQuestActor* QuestActor)
{

	if (QuestActor == CurrentQuest.QuestActor && QuestActor->QuestIndex == CurrentQuest.QuestIndex && 
		QuestActor->Quests[CurrentQuest.QuestIndex].NextQuestActor != NULL)
	{

		
		
		CurrentQuest.QuestActor = QuestActor->Quests[CurrentQuest.QuestIndex].NextQuestActor;
		CurrentQuest.QuestIndex = QuestActor->Quests[CurrentQuest.QuestIndex].ActorNextTaskIndex;
		CurrentQuest.QuestActor->QuestIndex = CurrentQuest.QuestIndex;
		CurrentQuest.QuestActor->SetInteractable(true);

		OnQuestChanged.Broadcast(CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].QuestDescription);

	}

}


void UCoreQuestSubsystem::SetFirstQuest(ACoreQuestActor* QuestActor, int QuestIndex)
{

	CurrentQuest.QuestActor = QuestActor;
	CurrentQuest.QuestIndex = QuestIndex;
	CurrentQuest.QuestActor->QuestIndex = CurrentQuest.QuestIndex;

	OnQuestChanged.Broadcast(CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].QuestDescription);

}

void UCoreQuestSubsystem::CheckQuestActor(ACoreQuestActor* ActorToCheck, bool& Result)
{
	if (CurrentQuest.QuestActor != NULL)
	{
		if (CurrentQuest.QuestActor == ActorToCheck)
			Result = true;
		else
			Result = false;
	}
	else
	{
		Result = false;
	}
	

}