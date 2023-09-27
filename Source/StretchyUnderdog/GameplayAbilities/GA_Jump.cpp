// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilities/GA_Jump.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "AbilitySystemLog.h"
#include "Characters/ShishaCharacterBase.h"


UGA_Jump::UGA_Jump()
{
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

}

bool UGA_Jump::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags,
	FGameplayTagContainer* OptionalRelevantTags) const
{

	if (!ActorInfo || !ActorInfo->AvatarActor.IsValid())
	{
		return false;
	}

	const ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
	if(!Character || !Character->CanJump())
	{
		return false;
	}

	if(!Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags))
	{
		return false;
	}

	return true;
}

void UGA_Jump::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	CharacterJumpStop();
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UGA_Jump::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                               const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	if(HasAuthorityOrPredictionKey(ActorInfo, &ActivationInfo))
	{
		if(!CommitAbility(Handle, ActorInfo, ActivationInfo))
		{
			return;
		}

		CharacterJumpStart();

		if(UAbilitySystemComponent* AbilitySystemComponent = ActorInfo->AbilitySystemComponent.Get())
		{
			FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
			FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(JumpEffect, 1, EffectContext);
			if(SpecHandle.IsValid())
			{
				const FActiveGameplayEffectHandle ActiveEffect = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
				if(!ActiveEffect.WasSuccessfullyApplied())
				{
					const ACharacter* Character = GetCharacterFromActorInfo();
					UE_LOG(LogTemp, Error, TEXT("Failed to apply jump effect %s"), *GetNameSafe(Character))
				}
			}
		}
	}
}

void UGA_Jump::CharacterJumpStart()
{
	if (AShishaCharacterBase* Character = GetCharacterFromActorInfo())
	{
		if (Character->IsLocallyControlled() && !Character->bPressedJump)
		{
			Character->UnCrouch();
			Character->Jump();
		}
	}
}

void UGA_Jump::CharacterJumpStop()
{
	if (AShishaCharacterBase* Character = GetCharacterFromActorInfo())
	{
		if (Character->IsLocallyControlled() && Character->bPressedJump)
		{
			Character->StopJumping();
		}
	}
}
