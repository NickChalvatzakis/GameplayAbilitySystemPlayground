// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Characters/ShishaCharacterBase.h"
#include "ShishaGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class STRETCHYUNDERDOG_API UShishaGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability")
	AShishaCharacterBase* GetCharacterFromActorInfo() const;
};
