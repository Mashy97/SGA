// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{
	
	// Widget Blueprinter
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClassFinder(TEXT("/Game/UI/WBP_Shop"));
	if (WidgetClassFinder.Succeeded()) {
		WidgetClass = WidgetClassFinder.Class;

		UE_LOG(LogTemp, Warning, TEXT("WidgetClassFinder"));
	}
	
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (WidgetClass != nullptr) {
		WidgetInstance = CreateWidget<UUserWidget>(this, WidgetClass);


		if (WidgetInstance != nullptr) {
			WidgetInstance->AddToViewport();

			UE_LOG(LogTemp, Warning, TEXT("WidgetInstance"));
		}
	}
	
}
