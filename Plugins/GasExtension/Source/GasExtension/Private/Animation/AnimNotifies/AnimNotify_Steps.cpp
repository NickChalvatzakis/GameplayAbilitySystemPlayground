// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNotifies/AnimNotify_Steps.h"
#include "Character/CharacterBase.h"
#include "Components/Actor/FootstepsComponent.h"
void UAnimNotify_Steps::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	check(MeshComp);

	ACharacterBase* Character = MeshComp ? Cast<ACharacterBase>(MeshComp->GetOwner()) : nullptr;

	if(Character)
	{
		if(UFootstepsComponent* FootstepsComponent = Character->GetFootstepsComponent())
		{
			FootstepsComponent->HandleFootstep(Foot);
		}
	}
}
