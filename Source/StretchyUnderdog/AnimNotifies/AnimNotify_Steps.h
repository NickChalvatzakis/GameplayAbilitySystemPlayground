// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShishaTypes.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_Steps.generated.h"

/**
 * 
 */
UCLASS()
class STRETCHYUNDERDOG_API UAnimNotify_Steps : public UAnimNotify
{
	GENERATED_BODY()
public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	UPROPERTY(EditAnywhere)
	EFoot Foot;
	
};
