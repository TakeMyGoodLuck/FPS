// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreWorldTimeManager.h"
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

	FTimerHandle EnergyTimerHandle;
	FTimerHandle DelayHandle;
	FTimerHandle HungryHandle;
	FTimerHandle ThirstHandle;
	FTimerHandle EnergyRestoreHandle;
	FTimerHandle TemperaturHandle;
	FTimerHandle OverheatHandle;

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

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats", meta = (DispalyName = "On Energy"))
		void OnEnergy(float Energy);

	

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

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats|Thirst", meta = (DispalyName = "On Thirst Max"))
		void OnThirstMax();

	UFUNCTION(BlueprintCallable, Category = "Player Stats|Thirst", meta = (DisplayName = "Feed Thirst"))
		void FeedThirst(float DrinkValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats|Thirst", meta = (DispalyName = "On Thirst"))
		void OnThirst(float Thirst);


		//Sleeping

	UFUNCTION(BlueprintCallable, Category = "Player Stats|Sleeping", meta = (DisplayName = "Sleep"))
		void Sleep(float SleepTime);

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats|Sleeping", meta = (DisplayName = "Wake On Hunger"))
		void WakeOnHunger();

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats|Sleeping", meta = (DisplayName = "Wake On Thirst"))
		void WakeOnThirst();


		//Temperature

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats|Temperature", meta = (DisplayName = "On Overheat"))
		void OnOverheat();

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats|Temperature", meta = (DisplayName = "On Temperature Updated"))
		void OnTemperatureUpdated(float Temperature);

	UFUNCTION(BlueprintCallable, Category = "Player Stats|Temperature", meta = (DisplayName = "Set Heating State"))
		void SetHeatingState(bool Heating);







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

	UPROPERTY(BlueprintReadWrite, Category = "PlayerStats")
		ACoreWorldTimeManager* TimeManager;

	UPROPERTY(EditAnywhere, Category = "Player Stats|Sleeping", meta = (DisplayName = "Sleep Duration (Real Time Seconds)", ClampMin = "0"))
		float SleepDuration;

	UPROPERTY(EditAnywhere, Category = "Player Stats|Sleeping", meta = (DisplayName = "Sleeping Energy Recovery (%/Hour)", ClampMin = "0", ClampMax = "100"))
		float EnergyRecover;


	UPROPERTY(EditAnywhere, Category = "Player Stats|Temperatur", meta = (DisplayName = "Heating up on Sun(%/sec)", ClampMin = "0", ClampMax = "100"))
		float HeatingUp;

	UPROPERTY(EditAnywhere, Category = "Player Stats|Temperatur", meta = (DisplayName = "CoolindDown (%/sec)", ClampMin = "0", ClampMax = "100"))
		float Cooling;
	

public:

	float fStamina, fWait, x, fEnergy, fEDelay, fHungry, fThirst, fHeat;
	bool bRestore, bDelay, bEnergy, bHungryLow, bThirstLow, bSleeping, bHeatingUp, bOverheat;
	float fEnergyTimerSpd;
	float fTimeSpeed;
	
	
	void FRestore();
	void FDelay(float DTime);


	
	void FReduceEnergy();
	void FEnergyTimer(float Time);
	void FSleepTimer(float Time);
	void FEndSleep();


	void FHungryDecrease();
	void FHungryTimer(float Time);


	void FThirstDecrease();
	void FThirstTimer(float Time);

	void FEnergyRestore();
	void FEnergyRestoreTimer(float Time);


	void FTemperatureTimer(float Time);
	void FTemperature();
	void FOverheat();
		


};
