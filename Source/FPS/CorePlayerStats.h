// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CorePlayerStats.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class FPS_API UCorePlayerStats : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCorePlayerStats();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	//UFuctions

		//Stamina

	UFUNCTION(BlueprintCallable, Category = "Player Stats", meta = (DisplayName = "Reduce Stamina"))
		void StaminaReduce(float StaminaCost);

	UFUNCTION(BlueprintPure, Category = "Player Stats", meta = (DisplayName = "Get Stamina"))
		void GetStamina(float &Stamina);

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats", meta = (DispalyName = "On Stamina Restoring"))
		void OnStaminaRestoring(float Stamina);

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats", meta = (DispalyName = "On Stamina Reduced"))
		void OnStaminaReduced(float Stamina);

		//Energy

	UFUNCTION(BlueprintPure, Category = "Player Stats", meta = (DisplayName = "Get Energy"))
		void GetEnergy(float& Energy);

	UFUNCTION(BlueprintCallable, Category = "Player Stats", meta = (DisplayName = "Reduce Energy"))
		void EnergyReduce(float EnergyCost);

	UFUNCTION(BlueprintCallable, Category = "Player Stats", meta = (DisplayName = "Restore Energy"))
		void EnergyRestore();

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats", meta = (DispalyName = "On Energy Reduced"))
		void OnEnergyReduced(float Energy);

	

	//UProperties

	UPROPERTY(EditAnywhere, Category = "Player Stats", meta = (DisplayName = "0 stamina wait time (sec)", ClampMin = "0"))
		float MaxWait;

	UPROPERTY(EditAnywhere, Category = "Player Stats", meta = (DisplayName = "Default stamina wait time (sec)", ClampMin = "0"))
		float DefWait;

	UPROPERTY(EditAnywhere, Category = "Player Stats", meta = (DisplayName = "Energy consumption per hour (%)", ClampMin = "0", ClampMax = "100"))
		float EnergyRate;

public:

	float fStamina, fWait, x, fEnergy, fEDelay;
	bool bRestore, bDelay, bEnergy;
	
	
	
	void FRestore();
	void FDelay(float DTime);
	void FEnergy(float DTime);

};
