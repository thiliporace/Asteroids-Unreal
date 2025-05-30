// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MeteorActor.generated.h"

UCLASS()
class METEORS_API AMeteorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMeteorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
