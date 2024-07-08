// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class GAMEANIMATIONSAMPLE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	AMyCharacter();

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;


	// Sprint Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = input, meta = (AloowprivateAccess = "true"))
	UInputAction* Sprint_Action;

	// Dash Input Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = input, meta = (AloowprivateAccess = "true"))
	UInputAction* DashAction;

	UAnimMontage* DashMontage;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Moving
	//void Move(const FInputActionValue& Value);

	// Sprint
	void Sprint_Start();

	void Sprint_End();

	// Dash
	void Dashing();
	float DashDistance = 2500;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
