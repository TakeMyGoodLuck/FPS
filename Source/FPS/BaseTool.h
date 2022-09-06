// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseInstrumentObject.h"
#include "BaseTool.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API ABaseTool : public ABaseInstrumentObject
{
	GENERATED_BODY()

public:

	ABaseTool();

	virtual void OnInstrumentUsed(float& StaminaCost, float& NextUseDelay) override;


	UPROPERTY(BlueprintReadOnly, EditAnyWhere, Category = "Instrument|Tool")
		float BreakingAmountPerUse;

	UPROPERTY(BlueprintReadOnly, Category = "Instrument|Tool")
		float Sharpness;

	
	
};
