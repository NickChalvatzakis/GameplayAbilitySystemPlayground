// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilities/ShishaGameplayAbility.h"

AShishaCharacterBase* UShishaGameplayAbility::GetCharacterFromActorInfo() const
{
	return (CurrentActorInfo ? Cast<AShishaCharacterBase>(CurrentActorInfo->AvatarActor.Get()) : nullptr);
}
