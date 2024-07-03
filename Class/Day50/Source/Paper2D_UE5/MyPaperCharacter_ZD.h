// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "MyPaperCharacter_ZD.generated.h"


class UPaperFlipbook;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UCharacterMovementComponent;
class UPaperZDAnimationComponent;
class UInputAction;
struct FInputActionValue;
template <typename T> struct TObjectPtr;

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	/** 케릭터가 움직임이 없을때 동작 */
	Idle UMETA(DisplayName = "Idle"),

	/** The character is walking. */
	Walk UMETA(DisplayName = "Walk"),

	/** The character is running. */
	Run UMETA(DisplayName = "Run"),

	/** The character is performing a basic attack. */
	Attack01 UMETA(DisplayName = "Attack01"),

	/** The character is preparing to jump. */
	JumpReady UMETA(DisplayName = "Jump Ready"),

	/** The character is in the initial upward movement of a jump. */
	JumpUp UMETA(DisplayName = "Jump Up"),

	/** The character is at the peak of the jump and moving horizontally. */
	Jumping UMETA(DisplayName = "Jumping"),

	/** The character is falling down after a jump. */
	Falling UMETA(DisplayName = "Falling"),

	/** The character has landed on the ground after a jump. */
	Landing UMETA(DisplayName = "Landing")
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class PAPER2D_UE5_API AMyPaperCharacter_ZD : public APaperCharacter
{
	GENERATED_BODY()
public:
	AMyPaperCharacter_ZD();


protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:

	void StartJump();
	void StopJump();

	void Move(float Value);
	void Walk(float Value);

	//공격 Input 이벤트
	void Attack();

	void InitializeAnimations();
	void UpdateAnimation(ECharacterState NewState);
	void UpdateCharacter();
	//UFUNCTION()
	//void OnAttackFinished();

	void TurnRight();

public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TMap<ECharacterState, TObjectPtr<class UPaperFlipbook>> CharacterAnimations;


private:

	// Movement state
	bool bIsAttacking;
	bool bIsJumping;

	FVector2D MovementInput;
	FVector LastVelocity;
	
	ECharacterState CurrentState;
	
	// 카메라와 Spring Arm Components 를  추가함.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Movement", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCharacterMovementComponent> Movement;

	// Add PaperZD
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PaperZD", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperZDAnimationComponent> AnimationComponent;
};
