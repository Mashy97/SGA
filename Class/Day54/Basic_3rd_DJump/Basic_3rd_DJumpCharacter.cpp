// Copyright Epic Games, Inc. All Rights Reserved.

#include "Basic_3rd_DJumpCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ABasic_3rd_DJumpCharacter

ABasic_3rd_DJumpCharacter::ABasic_3rd_DJumpCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;


	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller	

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void ABasic_3rd_DJumpCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
}

void ABasic_3rd_DJumpCharacter::Tick(float DeltaTime)
{
	// Call the base class
	Super::Tick(DeltaTime);

}

void ABasic_3rd_DJumpCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
	bFirstJump = true;
}

bool ABasic_3rd_DJumpCharacter::IsFalling()
{	
	if (&UCharacterMovementComponent::FindFloor)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void ABasic_3rd_DJumpCharacter::SlideStart()
{
	if (!IsSliding)
	{	
		UE_LOG(LogTemplateCharacter, Error, TEXT("StartSliding"));
		IsSliding = true;
		GetCharacterMovement()->MaxWalkSpeed = SlideSpeed;
		GetCapsuleComponent()->SetCapsuleHalfHeight(48.f);

	}
}

void ABasic_3rd_DJumpCharacter::SlideEnd()
{
	if (IsSliding) {
		UE_LOG(LogTemplateCharacter, Error, TEXT("EndSliding"));

		IsSliding = false;
		GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
		GetCapsuleComponent()->SetCapsuleHalfHeight(96.f);
	}

}


void ABasic_3rd_DJumpCharacter::Dashing()
{
	const FVector ForwardDir = this->GetActorRotation().Vector();
	LaunchCharacter(ForwardDir * DashDistance, true, true);
	if (DashMontage)
	{
		PlayAnimMontage(DashMontage, 1, NAME_None);
	}
}

void ABasic_3rd_DJumpCharacter::SprintStart()
{
	if (!IsSprint)
	{
		IsSprint = true;
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
		UE_LOG(LogTemplateCharacter, Error, TEXT("StartSprint"));

	}
}
void ABasic_3rd_DJumpCharacter::SprintEnd()
{
	if (IsSprint)
	{
		IsSprint = false;
		GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
		UE_LOG(LogTemplateCharacter, Error, TEXT("EndSprint"));
	}
}

void ABasic_3rd_DJumpCharacter::CrouchStart()
{
		if (!GetCharacterMovement()->IsFalling() && !IsCrouch)
		{
			UE_LOG(LogTemplateCharacter, Error, TEXT("StartCrouch"));
			IsCrouch = true;
			GetCapsuleComponent()->SetCapsuleHalfHeight(48.f);
			GetCharacterMovement()->MaxWalkSpeed = CrouchSpeed;

		}
}

void ABasic_3rd_DJumpCharacter::CrouchEnd()
{
	if (IsCrouch)
	{	
		UE_LOG(LogTemplateCharacter, Error, TEXT("EndCrouch"));
		IsCrouch = false;
		GetCapsuleComponent()->SetCapsuleHalfHeight(96.f);
		GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
		IsJump = false;
	}
}

void ABasic_3rd_DJumpCharacter::DoubleJump()
{
	if (bFirstJump) 
	{
		bFirstJump = false;
		ACharacter::Jump();
	}
	else 
	{	// LaunchCharacter(FVector LaunchVelocity, bool bXYOverride, bool bZOverride)
		// (%f,%f,%f)") - (LaunchVelocity.X, LaunchVelocity.Y, LaunchVelocity.Z)
		LaunchCharacter(FVector(0.0f,0.0f,500.0f), false, true);
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void ABasic_3rd_DJumpCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
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
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ABasic_3rd_DJumpCharacter::DoubleJump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABasic_3rd_DJumpCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABasic_3rd_DJumpCharacter::Look);

		// Sliding
		EnhancedInputComponent->BindAction(SlideAction, ETriggerEvent::Started, this, &ABasic_3rd_DJumpCharacter::SlideStart);
		EnhancedInputComponent->BindAction(SlideAction, ETriggerEvent::Completed, this, &ABasic_3rd_DJumpCharacter::SlideEnd);

		// Dash
		EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Triggered, this, &ABasic_3rd_DJumpCharacter::Dashing);

		// Sprint
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &ABasic_3rd_DJumpCharacter::SprintStart);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &ABasic_3rd_DJumpCharacter::SprintEnd);
		
		// Crouch
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Started, this, &ABasic_3rd_DJumpCharacter::CrouchStart);
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Completed, this, &ABasic_3rd_DJumpCharacter::CrouchEnd);

	
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ABasic_3rd_DJumpCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ABasic_3rd_DJumpCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

