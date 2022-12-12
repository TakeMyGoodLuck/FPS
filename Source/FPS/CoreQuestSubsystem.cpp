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
		CurrentQuest.CurrentAmount++;

		if (CurrentQuest.CurrentAmount == QuestActor->Quests[CurrentQuest.QuestIndex].AmountToComplete)
		{

			

			if (QuestActor->Quests[CurrentQuest.QuestIndex].Hint == true)
				HideHint();
			CurrentQuest.QuestActor->Pointer->SetVisibility(false);
			CurrentQuest.InteractType = QuestActor->Quests[CurrentQuest.QuestIndex].NextActorInteractType;
			CurrentQuest.QuestActor = QuestActor->Quests[CurrentQuest.QuestIndex].NextQuestActor;
			CurrentQuest.QuestIndex = QuestActor->Quests[CurrentQuest.QuestIndex].ActorNextTaskIndex;
			CurrentQuest.QuestActor->QuestIndex = CurrentQuest.QuestIndex;
			CurrentQuest.QuestActor->Pointer->SetVisibility(true);

				
			OnQuestCompleted.Broadcast();
			
				
			CurrentQuest.CurrentAmount = 0;

			if (CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].Hint == true)
			{
				ShowHint(CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].HintText[0], CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].HintText[1]);
			}

			if (CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].Tutorial == true)
				ShowTutorial.Broadcast(CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].TutorialName, CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].TutorialText);
			
			if (CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].Dialog == true)
				ShowDialog(CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].DialogText);
		}
		
		
		OnQuestChanged.Broadcast(CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].QuestCaption, CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].QuestDescription, CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].AmountToComplete, CurrentQuest.CurrentAmount);
		
	}
}


void UCoreQuestSubsystem::SetFirstQuest(ACoreQuestActor* QuestActor, int QuestIndex, int InteractType)
{

	CurrentQuest.QuestActor = QuestActor;
	CurrentQuest.QuestActor->Pointer->SetVisibility(true);
	CurrentQuest.QuestIndex = QuestIndex;
	CurrentQuest.QuestActor->QuestIndex = CurrentQuest.QuestIndex;
	CurrentQuest.InteractType = InteractType;

	if (QuestActor->Quests[QuestIndex].Hint == true)
		ShowHint(CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].HintText[0], CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].HintText[1]);
	OnQuestChanged.Broadcast(CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].QuestCaption, CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].QuestDescription, CurrentQuest.QuestActor->Quests[CurrentQuest.QuestIndex].AmountToComplete, CurrentQuest.CurrentAmount);

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

void UCoreQuestSubsystem::SetQuestHolder(ACoreQuestActor* Actor)
{
	QuestHolder = Actor;
}

ACoreQuestActor* UCoreQuestSubsystem::GetQuestHolder()
{
	return QuestHolder;
}



void UCoreQuestSubsystem::ShowHint(FText Body, FText InText)
{
	CallHint.Broadcast(Body, InText);
}

void UCoreQuestSubsystem::HideHint()
{
	CallHideHint.Broadcast();
}

void UCoreQuestSubsystem::ShowDialog(FText Dialog)
{
	CallDialog.Broadcast(Dialog);
}