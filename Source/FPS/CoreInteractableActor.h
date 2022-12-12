// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreQuestActor.h"
#include "CoreInteractableActor.generated.h"

UCLASS()
class FPS_API ACoreInteractableActor : public ACoreQuestActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoreInteractableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;




	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (DisplayName = "Static Mesh"))
		UStaticMeshComponent* VisualMesh;

	UFUNCTION(BlueprintNativeEvent)
		void InteractCheck(UCoreInstrumentObject_* Instrument, bool& Success);
	
	UFUNCTION(BlueprintImplementableEvent)
		void OnInteracted();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Use Instrument"))
		void UseInstrument(UCoreInstrumentObject_* Instrument, bool& Success);

	UFUNCTION(BlueprintImplementableEvent)
		void InstrumentUsed(UCoreInstrumentObject_* Instrument);

	UFUNCTION(BlueprintCallable, Category = "Interactable")
		void Interact(UCoreInstrumentObject_* Instrument);

	UFUNCTION(BlueprintImplementableEvent, Category = "Interactable")
		void Interacted(UCoreInstrumentObject_* Instrument);



};
