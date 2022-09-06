// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseToolComponent.h"

UBaseToolComponent::UBaseToolComponent()
{
	SelfDamgePerUse = 3.f;
	StaminaToRepair = 10.f;
	RepairTime = 7.f;
	UseSpeed = 1.f;
	ToolHealth = 100.f;
}

void UBaseToolComponent::InstrumentUsed()
{
	
	ToolHealth = ToolHealth - SelfDamgePerUse;
	if (ToolHealth <= 0)
	{
		ToolHealth = 0;
		ToolBroken();
	}
	
	

}

void UBaseToolComponent::ToolBroken()
{
	IsPossibleToUse = false;
	OnToolBroken();

}

void UBaseToolComponent::Repair()
{

}

void UBaseToolComponent::RepairTool()
{
	Repair();
}


void UBaseToolComponent::GetHealth(float& Health)
{
	Health = ToolHealth;
}




