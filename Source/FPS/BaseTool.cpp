// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTool.h"


ABaseTool::ABaseTool()
{
	BreakingAmountPerUse = 0.03f;
	Sharpness = 1.f;

}

void ABaseTool::OnInstrumentUsed(float& StaminaCost, float& NextUseDelay)
{
	Super::OnInstrumentUsed(StaminaCost, NextUseDelay);

	Sharpness = Sharpness - BreakingAmountPerUse;
}

