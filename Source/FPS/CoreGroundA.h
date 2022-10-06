// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreInteractableActor.h"
#include "CoreGroundA.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EGroundType : uint8
{
	Grassed,
	Weeded,
	Plowed,
	Seeded
};

UCLASS()
class FPS_API ACoreGroundA : public ACoreInteractableActor
{
	GENERATED_BODY()
	

public:

	ACoreGroundA();

public:

	UPROPERTY(BlueprintReadWrite, Category = "Ground", meta = (DisplayName = "Ground Type"))
		TEnumAsByte<EGroundType> GroundType;


};
