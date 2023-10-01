// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Actor/FootstepsComponent.h"
#include "PhysicalMaterials/PhysicalMaterialBase.h"
#include "Character/CharacterBase.h"
#include "Kismet/GameplayStatics.h"

#include "DrawDebugHelpers.h"

static TAutoConsoleVariable<int32> CVarShowFootsteps(
	TEXT("ShowDebugFootsteps"), 
	0, 
	TEXT("Draws debug info about footsteps"),
	ECVF_Cheat);

// Sets default values for this component's properties
UFootstepsComponent::UFootstepsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UFootstepsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UFootstepsComponent::HandleFootstep(EFoot Foot)
{
	if(ACharacterBase* Character = Cast<ACharacterBase>(GetOwner()))
	{
		const int32 DebugShowFootsteps = CVarShowFootsteps.GetValueOnAnyThread();
		if(USkeletalMeshComponent* Mesh = Character->GetMesh())
		{
			
			FHitResult HitResult;
			const FVector SocketLocation = Mesh->GetSocketLocation(Foot == EFoot::Left ? LeftFootSocketName : RightFootSocketName);
			const FVector Location = SocketLocation + FVector::UpVector * 20;

			FCollisionQueryParams QueryParams;
			QueryParams.bReturnPhysicalMaterial = true;
			QueryParams.AddIgnoredActor(Character);

			if(GetWorld()->LineTraceSingleByChannel(
				HitResult,
				Location, 
				Location + FVector::UpVector * -50.0f,
				ECC_WorldStatic, QueryParams
			))
			{
				if(HitResult.bBlockingHit)
				{
					if(HitResult.PhysMaterial.Get())
					{
						UPhysicalMaterialBase* PhysicalMaterial = Cast<UPhysicalMaterialBase>(HitResult.PhysMaterial.Get());

						if(PhysicalMaterial)
						{
							UGameplayStatics::PlaySoundAtLocation(this, PhysicalMaterial->FootstepsSound, Location, 1.f);
							
								if(DebugShowFootsteps > 0)
								{
									DrawDebugString(GetWorld(), Location, GetNameSafe(PhysicalMaterial), nullptr, FColor::White, 4.f);
								}
						}
					}
					if(DebugShowFootsteps > 0)
					{
						DrawDebugSphere(GetWorld(), Location, 16, 16, FColor::Red, false, 4.f);
					}
				}
				else
				{
					if(DebugShowFootsteps > 0)
					{
						DrawDebugLine(GetWorld(), Location, Location + FVector::UpVector * -50.0f, FColor::Red, false, 4.0f, 0 , 1.0f);
					}
				}
			}
			else
			{
				if(DebugShowFootsteps > 0)
					{
						DrawDebugLine(GetWorld(), Location, Location + FVector::UpVector * -50.0f, FColor::Red, false, 4.0f, 0 , 1.0f);
						DrawDebugSphere(GetWorld(), Location, 16, 16, FColor::Red, false, 4.0f);
					}
			}

		}
	}
}
