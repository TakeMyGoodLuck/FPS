// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CoreInteractableActor.h"
#include "CoreInstrumentObject_.generated.h"

UENUM(BlueprintType)
enum class EInstrumentType : uint8
{
	Scythe,
	Hoe,
	Rake,
	Seeds,
	Bucket,
	Gloves,
	Hammer
};
/**
 * 
 */



UCLASS(Blueprintable, Abstract)
class FPS_API UCoreInstrumentObject_ : public UObject
{
	GENERATED_BODY()

public:

	UCoreInstrumentObject_();
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument", meta = (DisplayName = "Instrument Name"))
		FName InstrName;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument", meta = (DisplayName = "Quick Access Image"))
		UTexture2D* QAImage;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument", meta = (DisplayName = "Stamina Cost Per Use (%)", ClampMin = "0", ClampMax = "100"))
		float Stamina_Cost_Per_Use;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument", meta = (DisplayName = "Interact Time", ClampMin = "0"))
		float InteractTime;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument", meta = (DisplayName = "Release Time", ClampMin = "0"))
		float ReleaseTime;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument", meta = (DisplayName = "Energy Cost Per Use (%)", ClampMin = "0", ClampMax = "100"))
		float EnergyCost;
	

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Instrument", meta = (DisplayName = "Spawn Transform"))
		FTransform SpwnTransform;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Instrument", meta = (DisplayName = "Instrument"))
		TEnumAsByte<EInstrumentType> InstrType;
	
	UPROPERTY(BlueprintReadWrite, Category = "Instrument", meta = (DisplayName = "Selector Index", ClampMin = "0"))
		int SlctIndex;

		
public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Instrument")
		void OnIstrumentUsed();

	UFUNCTION(BlueprintCallable, Category = "Instrument")
		void UseInstrument(ACoreInteractableActor* Interacted_Actor, bool& Success, float& Stamina_Cost, float& Energy_Cost, float& Interact_Time, float& Release_Time);

	

protected:

	virtual void InstrumentUsed();
	
	
public:

	bool IsPossibleToUse;
	
};

