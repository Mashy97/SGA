// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPaperCharacter_ZD.h"

#include "Camera/CameraComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "MyPlayerController.h"

#include "PaperFlipbookComponent.h"
#include "PaperZDAnimationComponent.h"
#include "EnhancedInputComponent.h"



AMyPaperCharacter_ZD::AMyPaperCharacter_ZD()
{

    AnimationComponent = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("Animation"));

    if (AnimationComponent)
    {
        AddInstanceComponent(AnimationComponent.Get());
        AnimationComponent.Get()->RegisterComponent();
    }

    //카메라, 스프링암 컴퍼넌트를 값 세팅
    // Spring Arm Component
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 300.0f;
    SpringArm->SetRelativeRotation(FRotator(-10.0f, -90.0f, 0.0f)); //횡스크롤 화면 
    SpringArm->bDoCollisionTest = false;
    SpringArm->bInheritPitch = false;
    SpringArm->bInheritYaw = false;
    SpringArm->bInheritRoll = false;

    // Camera Component
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

    //점프관련 수치 초기화
        // Configure character movement
    GetCharacterMovement()->GravityScale = 2.0f;
    GetCharacterMovement()->AirControl = 0.80f;
    GetCharacterMovement()->JumpZVelocity = 1000.f;
    GetCharacterMovement()->GroundFriction = 3.0f;
    GetCharacterMovement()->MaxWalkSpeed = 600.0f;
    GetCharacterMovement()->MaxFlySpeed = 600.0f;


    bIsAttacking = false;
    bIsJumping = false;
    PrimaryActorTick.bCanEverTick = true;

}


void AMyPaperCharacter_ZD::BeginPlay()
{
    Super::BeginPlay();

    bIsAttacking = false;

    InitializeAnimations();

  

}



void AMyPaperCharacter_ZD::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    UpdateCharacter();
}


void AMyPaperCharacter_ZD::Move(float Value)
{
    if (!bIsAttacking && bIsJumping == false)
    {
        AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
        TurnRight();
    }
}


void AMyPaperCharacter_ZD::Walk(float Value)
{
}


void AMyPaperCharacter_ZD::StartJump()
{
    UE_LOG(LogTemp, Warning, TEXT("Start_Jump!"));

    if (CurrentState != ECharacterState::JumpReady)
    {
        Jump();
        bIsJumping = true;

        UpdateAnimation(ECharacterState::JumpReady);
    }
    
}

void AMyPaperCharacter_ZD::StopJump()
{
    UE_LOG(LogTemp, Warning, TEXT("Stop_Jump!"));

    StopJumping();
    bIsJumping = false;
    UpdateAnimation(ECharacterState::Landing);
    
}

void AMyPaperCharacter_ZD::Attack()
{
    if (!bIsAttacking && bIsJumping == false && CurrentState != ECharacterState::Attack01)
    {
        bIsAttacking = true;

        UpdateAnimation(ECharacterState::Attack01);
        GetSprite()->SetLooping(false);
        GetSprite()->PlayFromStart();
    }
}

void AMyPaperCharacter_ZD::TurnRight()
{
    const FVector PlayerVelocity = GetVelocity();
    const float PlayerSpeed = PlayerVelocity.Size();

    // 방향에 따른 캐릭터 회전
    if (Controller != nullptr)
    {

        if (PlayerVelocity.X < 0.0f)
        {
            GetSprite()->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
        }
        else if (PlayerVelocity.X > 0.0f)
        {
            GetSprite()->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
        }
    }
}

void AMyPaperCharacter_ZD::InitializeAnimations()
{

}

void AMyPaperCharacter_ZD::UpdateAnimation(ECharacterState NewState)
{
    if (CharacterAnimations.IsEmpty()) return;

    if (CharacterAnimations.Contains(NewState))
    {
        TObjectPtr<UPaperFlipbook> DesiredAnimation = CharacterAnimations[NewState];
        if (GetSprite()->GetFlipbook() != DesiredAnimation)
        {
            GetSprite()->SetFlipbook(DesiredAnimation);
            CurrentState = NewState;
        }
    }
}

void AMyPaperCharacter_ZD::UpdateCharacter()
{
    const FVector PlayerVelocity = GetVelocity();
    const float PlayerSpeed = PlayerVelocity.Size();

    if (!bIsAttacking)
    {
        if (bIsJumping)
        {
            switch (CurrentState)
            {
            case ECharacterState::JumpReady:
                if (PlayerVelocity.Z > 0)
                {
                    UpdateAnimation(ECharacterState::JumpUp);
                }
                break;

            case ECharacterState::JumpUp:
                if (PlayerVelocity.Z <= 0)
                {
                    UpdateAnimation(ECharacterState::Jumping);
                }
                break;

            case ECharacterState::Jumping:
                if (PlayerVelocity.Z < 0)
                {
                    UpdateAnimation(ECharacterState::Falling);
                }
                break;

            case ECharacterState::Falling:
                if (GetCharacterMovement()->IsMovingOnGround())
                {
                    StopJump();
                }
                break;

            case ECharacterState::Landing:

                if (PlayerSpeed > 0.0f)
                {
                    UpdateAnimation(ECharacterState::Run);
                }
                else
                {
                    UpdateAnimation(ECharacterState::Idle);
                }
                break;

            default:
                if (PlayerSpeed > 0.0f)
                {
                    UpdateAnimation(ECharacterState::Run);
                }
                else
                {
                    UpdateAnimation(ECharacterState::Idle);
                }
                break;
            }

        }
        else
        {

            if (PlayerSpeed > 0.0f)
            {
                UpdateAnimation(ECharacterState::Run);
            }
            else
            {
                UpdateAnimation(ECharacterState::Idle);
            }
            // 방향에 따른 캐릭터 회전
            TurnRight();
        }

    }
}
