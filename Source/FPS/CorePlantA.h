// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreInteractableActor.h"
#include "CorePlantA.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API ACorePlantA : public ACoreInteractableActor
{
	GENERATED_BODY()

public:

		ACorePlantA();

	
public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Plant Actor", meta = (DisplayName = "Default Growth Speed (Sec/State)", ClampMin = "0"))
		float GrowthSpd;
	UPROPERTY(BlueprintReadOnly, Category = "Plant Actor", meta = (DisplayName = "Growth Acceleration", ClampMin = "0"))
		float GrAccel;
	UPROPERTY(EditAnywhere, Category = "Plant Actor", meta = (DisplayName = "Growth States Count", ClampMin = "0"))
		int MaxStates;

	UPROPERTY(BlueprintReadWrite, Category = "Plant Actor", meta = (DisplayName = "Number of Seeds", ClampMin = "0"))
		int SeedsAmount;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Plant Actor", meta = (DisplayName = "Harvest Per Seed", ClampMin = "0"))
		int HarvestPerSeed;

	UFUNCTION(BlueprintPure, Category = "Plant Actor", meta = (DisplayName = "Get Growth Speed"))
		void GetSpd(float& Growth_Speed);
	UFUNCTION(BlueprintPure, Category = "Plant Actor", meta = (DisplayName = "Get Growth State"))
		void GetState(int& Growth_State);

	UFUNCTION(BlueprintCallable, Category = "Plant Actor", meta = (DisplayName = "Grow Plant"))
		void GrowPlant();
	UFUNCTION(BlueprintImplementableEvent, Category = "Plant Actor", meta = (DisplayName = "On Plant Growed"))
		void OnPlantGrowed(int Growth_State);
		
private:


	int State;

};
