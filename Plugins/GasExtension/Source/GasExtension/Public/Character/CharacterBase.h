// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "GameTypes.h"
#include "Logging/LogMacros.h"
#include "GameFramework/Character.h"
#include "Components/Actor/FootstepsComponent.h"
#include "CharacterBase.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UAbilitySystemComponentBase;
class UAttributeSetBase;
class UGameplayEffect;
class UGameplayAbility;


UCLASS(config=Game)
class ACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	

public:
	// Sets default values for this character's properties
	ACharacterBase(const FObjectInitializer& ObjectInitializer);

	virtual void PostInitializeComponents() override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

	bool ApplyGameplayEffectToSelf(TSubclassOf<UGameplayEffect> Effect, FGameplayEffectContextHandle InEffectContext);

protected:
	void GiveAbilities();
	void ApplyStartupEffects();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	UPROPERTY(EditDefaultsOnly)
	UAbilitySystemComponentBase* AbilitySystemComponent;

	UPROPERTY(Transient)
	UAttributeSetBase* AttributeSet;


protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintCallable)
	FCharacterData GetCharacterData() const;

	UFUNCTION(BlueprintCallable)
	void SetCharacterData(const FCharacterData& InCharacterData);

	void OnJumpActionStarted();
	void OnJumpActionStopped();

	void OnCrouchActionStarted();
	void OnCrouchActionStopped();

	/*virtual void Jump() override;*/

	//Remove all effects with InAir tag
	virtual void Landed(const FHitResult& Hit) override;

	class UFootstepsComponent* GetFootstepsComponent() const;

protected:
	FCharacterData CharacterData;

	UFUNCTION()
	void OnRep_CharacterData();

	virtual void InitFromCharacterData(const FCharacterData& InCharacterData, bool bFromReplication = false);
	virtual void OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) override;
	virtual void OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProperties);

	UPROPERTY(EditDefaultsOnly, Category="GasExtension")
	class UCharacterDataAsset* CharacterDataAsset;

	UPROPERTY(BlueprintReadOnly, Category="GasExtension")
	class UFootstepsComponent* FootstepsComponent;

	UPROPERTY(EditDefaultsOnly, Category="GasExtension")
	FGameplayTag JumpEventTag;

	UPROPERTY(EditDefaultsOnly, Category="GasExtension")
	FGameplayTagContainer CrouchTags;

	UPROPERTY(EditDefaultsOnly, Category="GasExtension")
	FGameplayTagContainer InAirTags;

	UPROPERTY(EditDefaultsOnly, Category="GasExtension")
	TSubclassOf<UGameplayEffect> CrouchStateEffect;

};
