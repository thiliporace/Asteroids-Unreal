// Fill out your copyright notice in the Description page of Project Settings.

#include "MeteorActor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AMeteorActor::AMeteorActor() {
}

// Called when the game starts or when spawned
void AMeteorActor::BeginPlay()
{
	Super::BeginPlay();
	
	UProjectileMovementComponent* projectileMovementComponent = FindComponentByClass<UProjectileMovementComponent>();
	if (!projectileMovementComponent) {
		UE_LOG(LogTemp, Warning, TEXT("Projectile Movement Component is null!"), this);
		return;
	}
	projectileMovementComponent->InitialSpeed = FMath::RandRange(120, 350);
	projectileMovementComponent->Velocity = projectileMovementComponent->InitialSpeed * FMath::VRand();
	//UE_LOG(LogTemp, Log, TEXT("%s"),*projectileMovementComponent->Velocity.ToString());
}

