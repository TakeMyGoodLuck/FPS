// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DirectionalLight.h"
#include "Misc/OutputDeviceNull.h"
#include "CoreGameInstance.h"
#include "GameFramework/Actor.h"
#include "CoreWorldTimeManager.generated.h"


UCLASS()
class FPS_API ACoreWorldTimeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoreWorldTimeManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	
	// Properties

private:

	FTimerHandle WorldTimerHandle;
	UCoreGameInstance* GI;
	FOutputDeviceNull ar;

protected:

	UPROPERTY(EditAnywhere)
		AActor* Sun;

	UPROPERTY(EditAnywhere)
		ADirectionalLight* LightSource;

	UPROPERTY(EditAnywhere, Category = "Time Manager", meta = (DisplayName = "Time Speed"))
		float TimerSpd;

	UPROPERTY(EditAnywhere, Category = "Time Manager", meta = (DisplayName = "Time Rate (Real Minutes in 24 Game Hours"))
		float TimeRate;

	UFUNCTION(BlueprintPure)
		void GetTSPD(float& SPD);



	

	//Functions

private:

	void Timer();
	void SetGITimeSpeed();

	UFUNCTION()
		void SetTime();

	void UpdateSunPosition(float Minutes);

	void CalculateTime();

	float TimeSpeed;




	
};
