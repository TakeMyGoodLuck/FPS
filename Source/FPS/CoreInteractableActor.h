// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "CoreInteractableActor.generated.h"

UCLASS()
class FPS_API ACoreInteractableActor : public AStaticMeshActor
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

	UFUNCTION(BlueprintNativeEvent)
		void Interact(UCoreInstrumentObject_* Instrument, bool& Success);
	
	UFUNCTION(BlueprintImplementableEvent)
		void OnInteracted();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Interact"))
		void CInteract(UCoreInstrumentObject_* Instrument, bool& Success);
};
