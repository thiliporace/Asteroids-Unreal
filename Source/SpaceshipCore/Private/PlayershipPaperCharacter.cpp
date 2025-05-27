// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayershipPaperCharacter.h"

APlayershipPaperCharacter::APlayershipPaperCharacter(): playerMoveSpeed(5), playerRotateSpeed(3) {
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Construto"));
}

void APlayershipPaperCharacter::BeginPlay() {
	//Garante que o codigo da classe base tambem e chamado
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Begin plei"));

	//Pegar o subsistema do Enhanced Input
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller)) {
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Nao conseguiu criar Mapping Context"));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Nao conseguiu achar o Player Controller"));
	}
}

void APlayershipPaperCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Ticking..."));
}

void APlayershipPaperCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {
	
}

void APlayershipPaperCharacter::Move(const FInputActionValue& Value) {

}

void APlayershipPaperCharacter::Rotate(const FInputActionValue& Value) {

}


