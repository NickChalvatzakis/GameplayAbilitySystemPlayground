// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstances/ShishaGameInstnace.h"
#include "ShishaGameInstnace.h"

#include "AbilitySystemGlobals.h"

void UShishaGameInstnace::Init()
{
	Super::Init();

	UAbilitySystemGlobals::Get().InitGlobalData();

}
