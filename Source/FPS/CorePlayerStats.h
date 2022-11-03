// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreGameInstance.h"
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

private:

	UCoreGameInstance* GI;
	FTimerHandle EnergyTimerHandle;
	FTimerHandle DelayHandle;
	FTimerHandle HungryHandle;
	FTimerHandle ThirstHandle;

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
		void ReduceEnergy(float EnergyCost);

	UFUNCTION(BlueprintCallable, Category = "Player Stats", meta = (DisplayName = "Restore Energy"))
		void EnergyRestore();

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats", meta = (DispalyName = "On Energy Reduced"))
		void OnEnergyReduced(float Energy);

	UFUNCTION(BlueprintCallable, Category = "Player Stats", meta = (DisplayName = "Sleep"))
		void Sleep();

		//Hungry

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats|Hunger", meta = (DispalyName = "On Hungry Low"))
		void OnHungryLow(float Hungry);

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats|Hunger", meta = (DispalyName = "On Hungry Max"))
		void OnHungryMax();

	UFUNCTION(BlueprintCallable, Category = "Player Stats|Hunger", meta = (DisplayName = "Feed Hunger"))
		void FeedHungry(float FoodValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats|Hunger", meta = (DispalyName = "On Hungry"))
		void OnHungry(float Hungry);
	

		//Thirst

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats|Thirst", meta = (DispalyName = "On Thirst Low"))
		void OnThirstLow(float Hungry);

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats|Thirst", meta = (DispalyName = "On HThirst Max"))
		void OnThirstMax();

	UFUNCTION(BlueprintCallable, Category = "Player Stats|Thirst", meta = (DisplayName = "Feed Thirst"))
		void FeedThirst(float DrinkValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats|Thirst", meta = (DispalyName = "On Thirst"))
		void OnThirst(float Thirst);

	

	//UProperties

	UPROPERTY(EditAnywhere, Category = "Player Stats", meta = (DisplayName = "0 stamina wait time (sec)", ClampMin = "0"))
		float MaxWait;

	UPROPERTY(EditAnywhere, Category = "Player Stats", meta = (DisplayName = "Default stamina wait time (sec)", ClampMin = "0"))
		float DefWait;

	UPROPERTY(EditAnywhere, Category = "Player Stats", meta = (DisplayName = "Energy consumption per hour (%)", ClampMin = "0", ClampMax = "100"))
		float EnergyRate;

	UPROPERTY(EditAnywhere, Category = "Player Stats| Hunger", meta = (DisplayName = "Hungry Rate (%/Hour)", ClampMin = "0", ClampMax = "100"))
		float HungryRate;

	UPROPERTY(EditAnywhere, Category = "Player Stats| Hunger", meta = (DisplayName = "Hungry Low Limit (%)", ClampMin = "0", ClampMax = "100"))
		float HungryLow;

	UPROPERTY(EditAnywhere, Category = "Player Stats| Thirst", meta = (DisplayName = "Thirst Rate (%/Hour)", ClampMin = "0", ClampMax = "100"))
		float ThirstRate;

	UPROPERTY(EditAnywhere, Category = "Player Stats| Thirst", meta = (DisplayName = "Thirst Low Limit (%)", ClampMin = "0", ClampMax = "100"))
		float ThirstLow;

public:

	float fStamina, fWait, x, fEnergy, fEDelay, fHungry, fThirst;
	bool bRestore, bDelay, bEnergy, bHungryLow, bThirstLow;
	float fEnergyTimerSpd;
	
	
	void FRestore();
	void FDelay(float DTime);


	void FEnergy(float DTime);
	void FReduceEnergy();
	void FEnergyTimer();
	void FDelayTimer(float Time);
	void FEndSleep();


	void FHungryDecrease();
	void FHungryTimer(float Time);


	void FThirstDecrease();
	void FThirstTimer(float Time);
};
