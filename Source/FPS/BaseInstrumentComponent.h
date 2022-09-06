// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "BaseInstrumentComponent.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API UBaseInstrumentComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
		UBaseInstrumentComponent();

protected:

	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Instrument Component")
		void OnIstrumentUsed();

	UFUNCTION(BlueprintCallable, Category = "Instrument Component")
		void UseInstrument(float &Spent_Stamina, float& Next_Use_Delay);

protected:
	virtual void InstrumentUsed();

public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument Component", meta = (DisplayName = "Stamina Cost Per Use (%)", ClampMin = "0", ClampMax = "100"))
		float Stamina_Cost_Per_Use;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument Component")
		float Use_Delay;

private:
	float StaminaCost, UseDelay;
	
public:
	bool IsPossibleToUse;
};
