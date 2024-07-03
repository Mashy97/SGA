// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyPaperCharacter.h"
#include "MyPaperCharacter_ZD.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"

//#include "UObject/ConstructorHelpers.h"

AMyPlayerController::AMyPlayerController()
{
   
}

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(IMC_SideScroller.Get(), 1);
    }
}

void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
    {
        EnhancedInputComponent->BindAction(IA_Move.Get(), ETriggerEvent::Triggered, this, &AMyPlayerController::Move);
        EnhancedInputComponent->BindAction(IA_Walk.Get(), ETriggerEvent::Triggered, this, &AMyPlayerController::Walk);        
        EnhancedInputComponent->BindAction(IA_Attack.Get(), ETriggerEvent::Triggered, this, &AMyPlayerController::Attack);
        EnhancedInputComponent->BindAction(IA_Jump.Get(), ETriggerEvent::Triggered, this, &AMyPlayerController::Jump);
        EnhancedInputComponent->BindAction(IA_Jump.Get(), ETriggerEvent::Triggered, this, &AMyPlayerController::StopJumping);
    }
}

void AMyPlayerController::Move(const FInputActionValue& Value)
{
   
    if (APawn* ControlledPawn = GetPawn())
    {
        FVector2D MovementVector = Value.Get<FVector2D>();
        
        if (AMyPaperCharacter* MyCharacter = Cast<AMyPaperCharacter>(ControlledPawn))
        {
            MyCharacter->Move(MovementVector.X);
        }
        else if (AMyPaperCharacter_ZD* MyCharacter_ZD = Cast<AMyPaperCharacter_ZD>(ControlledPawn))
        {
            MyCharacter_ZD->Move(MovementVector.X);
        }
    }  


}

void AMyPlayerController::Walk(const FInputActionValue& Value)
{

}

void AMyPlayerController::Jump()
{
    if (APawn* ControlledPawn = GetPawn())
    {
        if (AMyPaperCharacter_ZD* MyCharacter_ZD = Cast<AMyPaperCharacter_ZD>(ControlledPawn))
        {
            MyCharacter_ZD->StartJump();
        }
    }
}

void AMyPlayerController::StopJumping()
{
    if (APawn* ControlledPawn = GetPawn())
    {
        if (AMyPaperCharacter_ZD* MyCharacter_ZD = Cast<AMyPaperCharacter_ZD>(ControlledPawn))
        {
            MyCharacter_ZD->StopJump();
        }
    }
}

void AMyPlayerController::Attack(const FInputActionValue& Value)
{
    if (APawn* ControlledPawn = GetPawn())
    {
        if (AMyPaperCharacter* MyCharacter = Cast<AMyPaperCharacter>(ControlledPawn))
        {
            MyCharacter->Attack();            
        }
        else if (AMyPaperCharacter_ZD* MyCharacter_ZD = Cast<AMyPaperCharacter_ZD>(ControlledPawn))
        {
            MyCharacter_ZD->Attack();
        }
    }
}

