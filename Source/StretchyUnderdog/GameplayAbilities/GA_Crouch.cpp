// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilities/GA_Crouch.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Characters/ShishaCharacterBase.h"

UGA_Crouch::UGA_Crouch()
{
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

bool UGA_Crouch::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags,
	FGameplayTagContainer* OptionalRelevantTags) const
{
	const ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
	if(!Character || !Character->CanCrouch())
	{
		return false;
	}

	if(!Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags))
	{
		return false;
	}

	return true;
}

void UGA_Crouch::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	if(HasAuthorityOrPredictionKey(ActorInfo, &ActivationInfo))
	{
		if(!CommitAbility(Handle, ActorInfo, ActivationInfo))
		{
			return;
		}

		Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);	

		CharacterCrouchStart();
	}
}

void UGA_Crouch::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	CharacterCrouchStop();
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UGA_Crouch::CharacterCrouchStart()
{
	if (AShishaCharacterBase* Character = GetCharacterFromActorInfo())
	{
		if (Character->IsLocallyControlled() && !Character->GetCharacterMovement()->bWantsToCrouch)
		{
			Character->Crouch();
		}
	}
}

void UGA_Crouch::CharacterCrouchStop()
{
	if (AShishaCharacterBase* Character = GetCharacterFromActorInfo())
	{
		if (Character->IsLocallyControlled())
		{
			Character->UnCrouch();
		}
	}
}
