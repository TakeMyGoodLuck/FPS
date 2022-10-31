// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreInteractableActor.h"
#include "CoreRepairable.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API ACoreRepairable : public ACoreInteractableActor
{
	GENERATED_BODY()


public:

	ACoreRepairable();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Repaired Mesh"))
		UStaticMesh* RMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "Broken Mesh"))
		UStaticMesh* BMesh;

	UPROPERTY(BlueprintReadWrite, meta = (DisplayName = "Is Broken"))
		bool IsBroken;
};
