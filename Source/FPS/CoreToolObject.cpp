// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreToolObject.h"

UCoreToolObject::UCoreToolObject()
{
	SelfDamgePerUse = 3.f;
	StaminaToRepair = 10.f;
	RepairTime = 7.f;
	UseSpeed = 1.f;
	ToolHealth = 100.f;

}

void UCoreToolObject::InstrumentUsed()
{
	ToolHealth = ToolHealth - SelfDamgePerUse;
	if (ToolHealth <= 0)
	{
		ToolHealth = 0;
		ToolBroken();
	}
}

void UCoreToolObject::ToolBroken()
{
	IsPossibleToUse = false;
	OnToolBroken();
}

void UCoreToolObject::Repair()
{
}

void UCoreToolObject::GetHealth(float& Health)
{
	Health = ToolHealth;
}

void UCoreToolObject::GetIsPossibleToUse(bool& Return_Value)
{
	Return_Value = IsPossibleToUse;
}

void UCoreToolObject::RepairTool()
{
	Repair();
}
