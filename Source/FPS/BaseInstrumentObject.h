// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseInstrumentObject.generated.h"




UCLASS()
class FPS_API ABaseInstrumentObject : public AActor
{
	GENERATED_BODY()
		
	
public:	
	// Sets default values for this actor's properties
	ABaseInstrumentObject();

	UPROPERTY(VisibleAnywhere, Category = "Instrument")
		UStaticMeshComponent* Mesh;
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Instrument|Events")
		void InstrumentUsed();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument")
		float StaminaCostPerUse;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument")
		float UseDelay;

	UFUNCTION(BlueprintCallable, Category = "Instrument")
		virtual void OnInstrumentUsed(float &StaminaCost, float &NextUseDelay);

	

private: 

	
	
	


};
