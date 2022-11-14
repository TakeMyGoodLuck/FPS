// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CoreGameInstance.generated.h"

/**
 * 
 */






UCLASS()
class FPS_API UCoreGameInstance : public UGameInstance
{
	GENERATED_BODY()

public: 

	UCoreGameInstance();
	
public:

	

	// Properties:





	

protected:

	float TimerSpd;
	float TimeSpd;

	
		//Functions:
	
public:

	

	void FIncrementTime(float AddMinutes);



	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Time Speed"))
		void GetTimerSpeed(float& TimerSpeed);

	
	void SetTimerSpeed(float TimerSpeed);

	void SetTimeSpeed(float TimeSpeed);

	void GetTimeSpeed(float& TimeSpeed);




		//Properties

public:

	


};
