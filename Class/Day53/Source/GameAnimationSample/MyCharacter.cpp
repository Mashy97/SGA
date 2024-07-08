// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyCharacter::Sprint_Start()
{

	float SprintSpeed = 2000.f;
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;

}

void AMyCharacter::Sprint_End()
{
	float RunSpeed = 500.f;

	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;

	UE_LOG(LogTemp, Warning, TEXT(" SprintEnd "));
	UE_LOG(LogTemp, Log, TEXT("Character Location :: %lf"), GetVelocity().Length());
}

void AMyCharacter::Dashing()
{
	const FVector ForwardDir = this->GetActorRotation().Vector();
	LaunchCharacter(ForwardDir * DashDistance, true, true);
	if (DashMontage)
	{
		PlayAnimMontage(DashMontage, 1, NAME_None);
	}
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {


		// Sprint
		EnhancedInputComponent->BindAction(Sprint_Action, ETriggerEvent::Started, this, &AMyCharacter::Sprint_Start);
		EnhancedInputComponent->BindAction(Sprint_Action, ETriggerEvent::Completed, this, &AMyCharacter::Sprint_End);

		// Dash
		EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Triggered, this, &AMyCharacter::Dashing);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT(" EnhancedInputCompnent Error "));
	}
	
}

