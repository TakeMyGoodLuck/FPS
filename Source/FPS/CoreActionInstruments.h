// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreInstrumentObject_.h"
#include "CoreActionInstruments.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API UCoreActionInstruments : public UCoreInstrumentObject_
{
	GENERATED_BODY()

public:

		UCoreActionInstruments();

public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument|Action Instrument", meta = (DisplayName = "Object Capacity", ClampMin = "0"))
		int capacity;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument|Action Instrument", meta = (DisplayName = "Amount Per Use", ClampMin = "0"))
		int amount;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument|Action Instrument", meta = (DisplayName = "Object Filling", ClampMin = "0"))
		int filling;

	virtual void InstrumentUsed() override;


	UFUNCTION(BlueprintCallable, Category = "Instrument|Action Instrument", meta = (DisplayName = "Fill In"))
		void Fill();

	UFUNCTION(BlueprintImplementableEvent, Category = "Instrument|Action Instrument", meta = (DisplayName = "On Filled"))
		void OnFilled();

	UFUNCTION(BlueprintImplementableEvent, Category = "Instrument|Action Instrument", meta = (DisplayName = "On Emptied"))
		void OnEmptied();

	UFUNCTION(BlueprintCallable)
		void SetUsePossibility();

};
