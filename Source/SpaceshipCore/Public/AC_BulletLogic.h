// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "AC_BulletLogic.generated.h" 


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class SPACESHIPCORE_API UAC_BulletLogic : public UActorComponent
{
	GENERATED_BODY()

public:
	UAC_BulletLogic();
	
	UFUNCTION(BlueprintCallable, Category = "Bullet")
	void InitializeBullet(const FVector& Direction);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet")
	UProjectileMovementComponent* ProjectileMovementComponent;
};
