#include "AnimationInstances/ShishaAnimInstance.h"
#include "Characters/ShishaCharacterBase.h"
#include "Animation/AnimSequenceBase.h"
#include "DataAssets/CharacterDataAsset.h"
#include "DataAssets/CharacterAnimationDataAsset.h"

UBlendSpace* UShishaAnimInstance::GetLocomotionBlendspace() const
{
	if(const AShishaCharacterBase* Char = Cast<AShishaCharacterBase>(GetOwningActor()))
	{
		const FCharacterData Data = Char->GetCharacterData();
		if(Data.CharacterAnimDataAsset)
		{
			Data.CharacterAnimDataAsset->CharacterAnimationData.MovementBlendspace;
		}
	}

	return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.MovementBlendspace : nullptr;

}

UAnimSequenceBase* UShishaAnimInstance::GetIdleAnimation() const
{
	if(const AShishaCharacterBase* Char = Cast<AShishaCharacterBase>(GetOwningActor()))
	{
		const FCharacterData Data = Char->GetCharacterData();
		if(Data.CharacterAnimDataAsset)
		{
			Data.CharacterAnimDataAsset->CharacterAnimationData.IdleAnimationAsset;
		}
	}

	return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.IdleAnimationAsset : nullptr;
}
