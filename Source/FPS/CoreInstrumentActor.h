// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoreInstrumentActor.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInstrumentInteracted);


UCLASS(Abstract)
class FPS_API ABaseInstrumentActor : public AActor
{
	GENERATED_BODY()
	

public:	
	// Sets default values for this actor's properties
	ABaseInstrumentActor();


	UPROPERTY(VisibleAnywhere)
		USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Static Mesh"))
		UStaticMeshComponent* VisualMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintImplementableEvent, Category = "InstrumentActor")
		void OnInstrumentUsed(float UseSpeed);


	UPROPERTY(BlueprintAssignable)
		FOnInstrumentInteracted OnInstrumentInteracted;

	UFUNCTION(BlueprintCallable)
		void CallDelegate();
};
