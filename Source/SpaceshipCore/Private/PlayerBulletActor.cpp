// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBulletActor.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
APlayerBulletActor::APlayerBulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerBulletActor::BeginPlay()
{
	Super::BeginPlay();

	projectileMovementComponent = FindComponentByClass<UProjectileMovementComponent>();
}

void APlayerBulletActor::InitializeBullet(const FVector& vector) {
	upVector = vector;
	
	if (projectileMovementComponent) {
		projectileMovementComponent->Activate();
		projectileMovementComponent->Velocity = upVector * projectileMovementComponent->InitialSpeed;
		
		//UE_LOG(LogTemp, Log, TEXT("%s, %s"),*projectileMovementComponent->Velocity.ToString(), *upVector.ToString());
	}

	else UE_LOG(LogTemp, Warning, TEXT("Projectile Movement Component is null!"), this);
}

