// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreInstrumentActor.h"
#include "CoreToolActor.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FPS_API ABaseToolActor : public ABaseInstrumentActor
{
	GENERATED_BODY()

		ABaseToolActor();

protected:

	virtual void BeginPlay() override;

public:
		

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument|Tool", meta = (DisplayName = "Use Speed (sec)", ClampMin = "0"))
		float UseSpeed;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument|Tool", meta = (DisplayName = "Self Damage Per Use (%)", ClampMin = "0", ClampMax = "100"))
		float SelfDamgePerUse;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument|Tool", meta = (DisplayName = "Stamina Cost To Repair (%)", ClampMin = "0", ClampMax = "100"))
		float StaminaToRepair;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument|Tool", meta = (DisplayName = "RepairTime (sec)", ClampMin = "0"))
		float RepairTime;

	UPROPERTY(BlueprintReadOnly, Category = "Instrument|Tool", meta = (DisplayName = "InitHealth", ExposeOnSpawn = "true"))
		float InitHealth;
	

protected:

	virtual void InstrumentUsed() override;
	virtual void ToolBroken();
	virtual void Repair();

private:

	float ToolHealth;

public:

	UFUNCTION(BlueprintPure, Category = "Instrument|Tool", meta = (DisplayName = "Get Tool Health"))
		void GetHealth(float& Health);

	UFUNCTION(BlueprintImplementableEvent, Category = "Instrument|Tool", meta = (DisplayName = "On Tool Broken"))
		void OnToolBroken();

	UFUNCTION(BlueprintCallable, Category = "Instrument|Tool", meta = (DisplayName = "Repair Tool"))
		void RepairTool();
	
};
