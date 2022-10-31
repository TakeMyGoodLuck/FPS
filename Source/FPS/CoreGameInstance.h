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

	
	void IncrementTime()
	{

		Minutes++;
		if (Minutes == 60)
		{
			Minutes = 0;
			Hours++;
			if (Hours == 24)
			{
				Hours = 0;
				Days++;
			}
		}

	}

	FTimeStruct()
	{
		Minutes = 0;
		Hours = 0;
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

	void FIncrementTime();

	UPROPERTY(BlueprintReadOnly)
		FTimeStruct STime;

	UFUNCTION(BlueprintPure)
		void GetTime(FTimeStruct & Time);
	
};
