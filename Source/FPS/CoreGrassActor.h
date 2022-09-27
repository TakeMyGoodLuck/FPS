// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreInteractableActor.h"
#include "CoreGrassActor.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API ACoreGrassActor : public ACoreInteractableActor
{
	GENERATED_BODY()
	
public:

	ACoreGrassActor();

	protected:

		virtual void BeginPlay() override;


public:

	UPROPERTY(EditAnywhere, Category = "Grass Actor", meta = (DisplayName = "Default Growth Speed (Sec/State)", ClampMin = "0"))
		float GrowthSpd;
	UPROPERTY(EditAnywhere, Category = "Grass Actor", meta = (DisplayName = "Growth acceleration (%)", ClampMin = "0"))
		float GrAccel;


	UFUNCTION(BlueprintCallable, Category = "Grass Actor", meta = (DisplayName = "Set Growth Speed"))
		void SetGrthSpd(float Speed);
	UFUNCTION(BlueprintCallable, Category = "Grass Actor", meta = (DisplayName = "Set Growth Acceleration"))
		void SetGrthAccel(float Acceleration);
	UFUNCTION(BlueprintPure, Category = "Grass Actor", meta = (DisplayName = "Get Growth Speed"))
		void GetGrthSpd(float &Speed);
	UFUNCTION(BlueprintPure, Category = "Grass Actor", meta = (DisplayName = "Get Growth Acceleration"))
		void GetGrthAccel(float& Acceleration);
	UFUNCTION(BlueprintPure, Category = "Grass Actor", meta = (DisplayName = "Get Grow State"))
		void GetState (int& GrowthState);

	UFUNCTION(BlueprintImplementableEvent, Category = "Grass Actor", meta = (DisplayName = "On Grass Growed"))
		void OnGrassGrowed();

	UFUNCTION(BlueprintCallable, Category = "Grass Actor", meta = (DisplayName = "Grow Grass"))
		void GrowGrass(bool &IsMax);

	UFUNCTION(BlueprintCallable, Category = "Grass Actor", meta = (DisplayName = "Reset Grass"))
		void Reset();

private:

	float GrSpeed, GrAcclr;
	int State;
	bool IsMaxState;
	
};
