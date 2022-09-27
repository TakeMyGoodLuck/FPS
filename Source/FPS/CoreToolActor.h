// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreInstrumentActor.h"
#include "CoreToolActor.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FPS_API ABaseToolActor : public ABaseInstrumentActor
{
	GENERATED_BODY()

		ABaseToolActor();

protected:

	virtual void BeginPlay() override;


	
};
