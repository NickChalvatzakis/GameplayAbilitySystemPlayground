// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShishaTypes.generated.h"

USTRUCT(BlueprintType)
struct FCharacterData
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GAS")
	TArray<TSubclassOf<class UGameplayEffect>> Effects;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GAS")
	TArray<TSubclassOf<class UGameplayAbility>> Abilities;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animation")
	class UCharacterAnimationDataAsset* CharacterAnimDataAsset;
};

USTRUCT(BlueprintType)
struct FCharacterAnimationData
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditDefaultsOnly)
	class UBlendSpace* MovementBlendspace = nullptr;

	UPROPERTY(EditDefaultsOnly)
	class UBlendSpace* CrouchMovementBlendspace = nullptr;

	UPROPERTY(EditDefaultsOnly)
	class UAnimSequenceBase* IdleAnimationAsset = nullptr;

	UPROPERTY(EditDefaultsOnly)
	class UAnimSequenceBase* IdleCrouchAnimationAsset = nullptr;
};

UENUM(BlueprintType)
enum class EFoot : uint8
{
	Left UMETA(DisplayName = "Left"),
	Right UMETA(DisplayName = "Right")
};