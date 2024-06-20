// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SGA_0613_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AMyPlayerController();

	virtual void BeginPlay() override;

public:
	
	// widget blueprinter
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyBPClass")
	TSubclassOf<UUserWidget> WidgetClass;

	UUserWidget* WidgetInstance;
	
};
