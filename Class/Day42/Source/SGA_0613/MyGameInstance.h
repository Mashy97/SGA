// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Blueprint/UserWidget.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SGA_0613_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UMyGameInstance();
	virtual void Init() override;
	void ControlBP_MyActor();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="MyBPClass")
	TSubclassOf<AActor> BP_MyActorClass;

	AActor* spawnActor;
};
