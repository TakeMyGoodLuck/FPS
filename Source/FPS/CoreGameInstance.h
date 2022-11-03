// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CoreGameInstance.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType)
struct FTimeStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
		int Minutes;
	UPROPERTY(BlueprintReadWrite)
		int Hours;
	UPROPERTY(BlueprintReadWrite)
		int Days;

	
	void IncrementTime(float AddMinutes)
	{
		
		Minutes = Minutes + static_cast<int>(AddMinutes);
		Hours = Hours + Minutes / 60;
		Days = Days + Hours / 24;
		Hours = Hours % 24;
		Minutes = Minutes % 60;
		
	}

	FTimeStruct()
	{
		Minutes = 0;
		Hours = 9;
		Days = 0;

	}

};




UCLASS()
class FPS_API UCoreGameInstance : public UGameInstance
{
	GENERATED_BODY()

public: 

	UCoreGameInstance();
	
public:

	

	// Properties:

	UPROPERTY(BlueprintReadOnly)
		FTimeStruct STime;



	

protected:

	float TimerSpd;
	float TimeSpd;

	
	//Functions:
	
public:

	

	void FIncrementTime(float AddMinutes);

	UFUNCTION(BlueprintPure)
		void GetTime(FTimeStruct& Time);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Time Speed"))
		void GetTimerSpeed(float& TimerSpeed);

	
	void SetTimerSpeed(float TimerSpeed);

	void SetTimeSpeed(float TimeSpeed);

	void GetTimeSpeed(float& TimeSpeed);
	
};
