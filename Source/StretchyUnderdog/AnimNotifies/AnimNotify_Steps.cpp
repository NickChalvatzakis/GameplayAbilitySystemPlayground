// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifies/AnimNotify_Steps.h"
#include "Characters/ShishaCharacterBase.h"
#include "Components/Actor/FootstepsComponent.h"
void UAnimNotify_Steps::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	check(MeshComp);

	AShishaCharacterBase* Character = MeshComp ? Cast<AShishaCharacterBase>(MeshComp->GetOwner()) : nullptr;

	if(Character)
	{
		if(UFootstepsComponent* FootstepsComponent = Character->GetFootstepsComponent())
		{
			FootstepsComponent->HandleFootstep(Foot);
		}
	}
}
