// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ShishaTypes.h"
#include "CharacterAnimationDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class STRETCHYUNDERDOG_API UCharacterAnimationDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	FCharacterAnimationData CharacterAnimationData;

	
};
