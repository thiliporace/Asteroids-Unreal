// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "PlayerBulletActor.h"

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
    virtual void PossessedBy(AController* NewController) override;

private:
    int playerRotateSpeed;
    float rotateAmount;
    
protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void Move(const FInputActionValue& Value);
    
    void Rotate(const FInputActionValue& Value);

    void ShootBullet(const FInputActionValue& Value);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    UInputMappingContext* DefaultMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    UInputAction* MoveAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    UInputAction* RotateAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    UInputAction* ShootBulletAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool isRotating;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool isMoving;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet")
    float delayBetweenShots;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool isShooting;

    UPROPERTY(EditDefaultsOnly, Category = "Bullet")
    TSubclassOf<APlayerBulletActor> playerBulletActor;
};