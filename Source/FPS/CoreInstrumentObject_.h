// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CoreInstrumentObject_.generated.h"


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
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Instrument")
		float Use_Delay;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Instrument", meta = (DisplayName = "Spawn Transform"))
		FTransform SpwnTransform;

public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Instrument")
		void OnIstrumentUsed();

	UFUNCTION(BlueprintCallable, Category = "Instrument")
		void UseInstrument(float& Spent_Stamina, float& Next_Use_Delay);

protected:

	virtual void InstrumentUsed();
		

public:

	bool IsPossibleToUse;
	
};
