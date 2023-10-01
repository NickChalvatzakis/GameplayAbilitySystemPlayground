#include "Animation/AnimationInstances/AnimInstanceBase.h"
#include "Character/CharacterBase.h"
#include "Animation/AnimSequenceBase.h"
#include "DataAssets/CharacterDataAsset.h"
#include "DataAssets/CharacterAnimationDataAsset.h"

UBlendSpace* UAnimInstanceBase::GetLocomotionBlendspace() const
{
	if(const ACharacterBase* Char = Cast<ACharacterBase>(GetOwningActor()))
	{
		const FCharacterData Data = Char->GetCharacterData();
		if(Data.CharacterAnimDataAsset)
		{
			Data.CharacterAnimDataAsset->CharacterAnimationData.MovementBlendspace;
		}
	}

	return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.MovementBlendspace : nullptr;

}

UAnimSequenceBase* UAnimInstanceBase::GetIdleAnimation() const
{
	if(const ACharacterBase* Char = Cast<ACharacterBase>(GetOwningActor()))
	{
		const FCharacterData Data = Char->GetCharacterData();
		if(Data.CharacterAnimDataAsset)
		{
			Data.CharacterAnimDataAsset->CharacterAnimationData.IdleAnimationAsset;
		}
	}

	return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.IdleAnimationAsset : nullptr;
}

UBlendSpace* UAnimInstanceBase::GetCrouchLocomotionBlendspace() const
{
	if(const ACharacterBase* Char = Cast<ACharacterBase>(GetOwningActor()))
	{
		const FCharacterData Data = Char->GetCharacterData();
		if(Data.CharacterAnimDataAsset)
		{
			Data.CharacterAnimDataAsset->CharacterAnimationData.CrouchMovementBlendspace;
		}
	}

	return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.CrouchMovementBlendspace : nullptr;
}

UAnimSequenceBase* UAnimInstanceBase::GetCrouchIdleAnimation() const
{
	if(const ACharacterBase* Char = Cast<ACharacterBase>(GetOwningActor()))
	{
		const FCharacterData Data = Char->GetCharacterData();
		if(Data.CharacterAnimDataAsset)
		{
			Data.CharacterAnimDataAsset->CharacterAnimationData.IdleCrouchAnimationAsset;
		}
	}

	return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.IdleCrouchAnimationAsset : nullptr;
}
