// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DirectionalLight.h"
#include "Misc/OutputDeviceNull.h"
#include "GameFramework/Actor.h"
#include "CoreWorldTimeManager.generated.h"

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

	float secs;
	


	void IncrementTime(float Time)
	{

		
		Minutes = static_cast<int>(Time);
		Hours = Minutes / 60;
		Days = Hours / 24;
		Hours = Hours % 24;
		Minutes = Minutes % 60;


	}

	FTimeStruct()
	{
		Minutes = 0;
		Hours = 0;
		Days = 0;

	}

};


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

	

	

	void UpdateSunPosition(float Minutes);


	
	float fCounter;

public:

	float TimeSpeed;

	void CalculateTime();

	UPROPERTY(BlueprintReadOnly)
		FTimeStruct STime;


};
