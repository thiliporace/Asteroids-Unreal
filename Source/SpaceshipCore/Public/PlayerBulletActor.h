// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "PlayerBulletActor.generated.h"

UCLASS()
class SPACESHIPCORE_API APlayerBulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerBulletActor();

	void InitializeBullet(const FVector& vector);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	float bulletLifeTime;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Components")
	UProjectileMovementComponent* projectileMovementComponent;
private:
	FVector upVector;
};
