
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CoreQuestComponent.generated.h"

USTRUCT(BlueprintType)
struct FQuestStructs
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText QuestDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		AActor* NextQuestActor;

	UPROPERTY(BlueprintReadOnly)
		bool Completed;



};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_API UCoreQuestComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCoreQuestComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	UPROPERTY(EditAnywhere)
		TArray<FQuestStructs> Quests;

	
public:

	


	
};
