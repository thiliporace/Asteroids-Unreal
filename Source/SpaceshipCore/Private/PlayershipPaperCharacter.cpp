// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayershipPaperCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/SphereComponent.h"

#include <iostream>
#include <ostream>

APlayershipPaperCharacter::APlayershipPaperCharacter(): rotateAmount(0) {}

void APlayershipPaperCharacter::BeginPlay() {
	//Garante que o codigo da classe base tambem e chamado
	Super::BeginPlay();

	//Pegar componente adicionado na blueprint (no construtor ele ainda nao foi adicionado)
	UFloatingPawnMovement* floatingMovementComponent = FindComponentByClass<UFloatingPawnMovement>();

	if (floatingMovementComponent) {
		playerRotateSpeed = floatingMovementComponent->TurningBoost;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Nao conseguiu pegar Floating Pawn Movement"));
	}

	//Pegar o subsistema do Enhanced Input
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller)) {
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Nao conseguiu criar Mapping Context"));
		}

		SetupPlayerInputComponent(PlayerController->InputComponent);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Nao conseguiu achar o Player Controller"));
	}
}

void APlayershipPaperCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayershipPaperCharacter::Move);
		EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Triggered, this, &APlayershipPaperCharacter::Rotate);
		EnhancedInputComponent->BindAction(ShootBulletAction, ETriggerEvent::Triggered, this, &APlayershipPaperCharacter::ShootBullet);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Nao conseguiu setar InputComponent do Player"));
	}
}

void APlayershipPaperCharacter::Move(const FInputActionValue& Value) {
	if (isRotating) return;
	const FVector upVector = GetActorUpVector();
	AddMovementInput(upVector); //Um Paper Character já usa Delta Time por padrão, não precisa botar aqui
}

void APlayershipPaperCharacter::Rotate(const FInputActionValue& Value) {
	if (isMoving) return;
	float deltaTime = GetWorld()->GetDeltaSeconds();
	float rotateDirection = Value.Get<float>();
	
	rotateAmount = rotateDirection * playerRotateSpeed * deltaTime;
	
	//FRotator newRotation = FRotator(GetControlRotation().Pitch, rotateAmount, GetControlRotation().Roll);
	FRotator currentRotation = GetActorRotation();
	currentRotation.Roll += rotateAmount;
	//UE_LOG(LogTemp, Log, TEXT("%f"),rotateAmount);
	
	SetActorRotation(currentRotation);
}

void APlayershipPaperCharacter::ShootBullet(const FInputActionValue& Value) {
	if (isShooting) return;
	if (playerBulletActor)
	{
		APlayerBulletActor* newBullet = GetWorld()->SpawnActor<APlayerBulletActor>(
			playerBulletActor, GetActorLocation() + GetActorUpVector() * 25, GetActorRotation());
		
		if (newBullet) {
			newBullet->InitializeBullet(GetActorUpVector());
		}
		else UE_LOG(LogTemp, Warning, TEXT("Nao conseguiu spawnar o Player Bullet Actor"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Nao conseguiu criar o Player Bullet Actor"));
	}
}



