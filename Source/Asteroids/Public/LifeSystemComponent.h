// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LifeSystemComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTEROIDS_API ULifeSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	ULifeSystemComponent();
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LifeSystem")
	int maxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LifeSystem")
	int health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LifeSystem")
	float invincibilityTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LifeSystem")
	bool canTakeDamage;
	
protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void TakeDamage(const int damage);
};
