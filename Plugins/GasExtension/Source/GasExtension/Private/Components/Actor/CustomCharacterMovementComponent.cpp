// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Actor/CustomCharacterMovementComponent.h"

/*
 * Small test to see if overriding character movement behavior is simple
 */
//bool UShishaCharacterMovementComponent::DoJump(bool bReplayingMoves)
//{
//	if ( CharacterOwner && CanAttemptJump() )
//	{
//		// Don't jump if we can't move up/down.
//		if (!bConstrainToPlane || FMath::Abs(PlaneConstraintNormal.Z) != 1.f)
//		{
//			if (HasCustomGravity())
//			{
//				FVector GravityRelativeVelocity = RotateWorldToGravity(Velocity);
//				GravityRelativeVelocity.Z = FMath::Max<FVector::FReal>(GravityRelativeVelocity.Z, JumpZVelocity);
//				Velocity = RotateGravityToWorld(GravityRelativeVelocity);
//			}
//			else
//			{
//				Velocity.X = FMath::Max<FVector::FReal>(Velocity.X, JumpZVelocity);
//			}
//			
//			SetMovementMode(MOVE_Falling);
//			return true;
//		}
//	}
//	
//	return false;
//}
