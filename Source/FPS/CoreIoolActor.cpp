// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreToolActor.h"

ABaseToolActor::ABaseToolActor()
{
	SelfDamgePerUse = 3.f;
	StaminaToRepair = 10.f;
	RepairTime = 7.f;
	UseSpeed = 1.f;
	ToolHealth = 100.f;
	InitHealth = ToolHealth;
}

void ABaseToolActor::BeginPlay()
{
	ToolHealth = InitHealth;
	if (ToolHealth == 0)
		IsPossibleToUse = false;
	Super::BeginPlay();
}

void ABaseToolActor::InstrumentUsed()
{

	ToolHealth = ToolHealth - SelfDamgePerUse;
	if (ToolHealth <= 0)
	{
		ToolHealth = 0;
		ToolBroken();
	}



}

void ABaseToolActor::ToolBroken()
{
	IsPossibleToUse = false;
	OnToolBroken();

}

void ABaseToolActor::Repair()
{

}

void ABaseToolActor::RepairTool()
{
	Repair();
}


void ABaseToolActor::GetHealth(float& Health)
{
	Health = ToolHealth;
}
