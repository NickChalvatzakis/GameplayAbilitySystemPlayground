// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "ShishaPhysicalMaterial.generated.h"

/**
 * 
 */
UCLASS()
class STRETCHYUNDERDOG_API UShishaPhysicalMaterial : public UPhysicalMaterial
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physical Mateiral")
	class USoundBase* FootstepsSound = nullptr;
	
};
