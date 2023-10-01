// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstances/GameInstanceBase.h"

#include "AbilitySystemGlobals.h"

void UGameInstanceBase::Init()
{
	Super::Init();

	UAbilitySystemGlobals::Get().InitGlobalData();

}
