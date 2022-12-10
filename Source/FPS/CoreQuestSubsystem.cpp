// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreQuestSubsystem.h"




UCoreQuestSubsystem::UCoreQuestSubsystem()
{

}

void UCoreQuestSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{

	
}

void UCoreQuestSubsystem::UpdateQuest(ACoreQuestActor* QuestActor, int InteractType)
{

	if (QuestActor == CurrentQuest.QuestActor && QuestActor->QuestIndex == CurrentQuest.QuestIndex && 
		QuestActor->Quests[CurrentQuest.QuestIndex].NextQuestActor != NULL &&
		InteractType == CurrentQuest.InteractType)
	{

		
		CurrentQuest.QuestActor->Pointer->SetVisibility(false);
		CurrentQuest.InteractType = QuestActor->Quests[CurrentQuest.QuestIndex].NextActorInteractType;
		CurrentQuest.QuestActor = QuestActor->Quests[CurrentQuest.QuestIndex].NextQuestActor;
		CurrentQuest.QuestIndex = QuestActor->Quests[CurrentQuest.QuestIndex].ActorNextTaskIndex;
		CurrentQuest.QuestActor->QuestIndex = CurrentQuest.QuestIndex;
		CurrentQuest.QuestActor->Pointer->SetVisibility(true);

		OnQuestChanged.Broadcast(CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].QuestCaption, CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].QuestDescription);

	}

}


void UCoreQuestSubsystem::SetFirstQuest(ACoreQuestActor* QuestActor, int QuestIndex, int InteractType)
{

	CurrentQuest.QuestActor = QuestActor;
	CurrentQuest.QuestActor->Pointer->SetVisibility(true);
	CurrentQuest.QuestIndex = QuestIndex;
	CurrentQuest.QuestActor->QuestIndex = CurrentQuest.QuestIndex;
	CurrentQuest.InteractType = InteractType;

	OnQuestChanged.Broadcast(CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].QuestCaption, CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].QuestDescription);

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

FCurrentQuestStruct UCoreQuestSubsystem::GetCurrentQuest()
{
	return CurrentQuest;
}