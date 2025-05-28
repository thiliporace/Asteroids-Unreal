// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayershipPaperCharacter.h"

#include <iostream>
#include <ostream>

APlayershipPaperCharacter::APlayershipPaperCharacter(): playerMoveSpeed(MAX_PLAYER_MOVE_SPEED), playerRotateSpeed(MAX_PLAYER_ROTATE_SPEED), rotateAmount(0) {
	PrimaryActorTick.bCanEverTick = true;
}

void APlayershipPaperCharacter::BeginPlay() {
	//Garante que o codigo da classe base tambem e chamado
	Super::BeginPlay();

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

void APlayershipPaperCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void APlayershipPaperCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayershipPaperCharacter::Move);
		EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Triggered, this, &APlayershipPaperCharacter::Rotate);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Nao conseguiu setar InputComponent do Player"));
	}
}

void APlayershipPaperCharacter::Move(const FInputActionValue& Value) {
	const FVector upVector = GetActorUpVector();
	float movementAmount = Value.Get<float>();
	
	AddMovementInput(upVector, movementAmount * playerMoveSpeed); //Faltando deltaTime (?)
	
	UE_LOG(LogTemp, Log, TEXT("%f"),movementAmount * playerRotateSpeed);
}

void APlayershipPaperCharacter::Rotate(const FInputActionValue& Value) {
	float rotateDirection = Value.Get<float>();
	//UE_LOG(LogTemp, Log, TEXT("%f"),rotateDirection);
	
	rotateAmount += rotateDirection * playerRotateSpeed;
	
	FRotator newRotation = FRotator(GetControlRotation().Pitch, rotateAmount, GetControlRotation().Yaw); //Faltando deltaTime (?)
	UE_LOG(LogTemp, Log, TEXT("%f"),newRotation.Yaw);

	UCapsuleComponent* capsuleComponent = GetCapsuleComponent();
	capsuleComponent->SetWorldRotation(newRotation);
	SetActorRotation(newRotation);
}


