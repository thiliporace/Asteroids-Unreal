// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

//Tem que ficar por ultimo
#include "PlayershipPaperCharacter.generated.h"

/**
 *
 */

UCLASS()
class SPACESHIPCORE_API APlayershipPaperCharacter : public APaperCharacter
{
    GENERATED_BODY()
public:
    APlayershipPaperCharacter();

private:
    int playerRotateSpeed;
    float rotateAmount;
    
protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void Move(const FInputActionValue& Value);
    
    void Rotate(const FInputActionValue& Value);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    UInputMappingContext* DefaultMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    UInputAction* MoveAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    UInputAction* RotateAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool isRotating;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool isMoving;
};