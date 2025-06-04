// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_BulletLogic.h"
#include "GameFramework/Actor.h"

UAC_BulletLogic::UAC_BulletLogic()
{
}

void UAC_BulletLogic::InitializeBullet(const FVector& Direction)
{
	if (ProjectileMovementComponent)
	{
		ProjectileMovementComponent->Activate(true); 
		ProjectileMovementComponent->Velocity = Direction.GetSafeNormal() * ProjectileMovementComponent->InitialSpeed;
		
		// UE_LOG(LogTemp, Log, TEXT("BulletLogicComponent: Velocity set to %s (Direction: %s, Speed: %f)"), *ProjectileMovementComponent->Velocity.ToString(), *Direction.ToString(), Speed);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("BulletLogicComponent: Projectile Movement Component is null during InitializeBullet on Actor %s!"), *GetOwner()->GetName());
	}
}

