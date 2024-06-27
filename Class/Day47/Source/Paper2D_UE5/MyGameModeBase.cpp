// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "MyPaperCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMyGameModeBase::AMyGameModeBase()
{
	// 블루프린터 클래스를 디폴트 Pawn 클래스로 세팅하는 방법
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/BP_MyChar"));	
		
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// 블루프린터 클래스를 디폴트 PlayerController 클래스로 세팅하는 방법
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/BP_MyController"));
	
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}

	//일반 C++ 클래스를  세팅하는 방법
	//DefaultPawnClass = AMyPaperCharacter::StaticClass();
	//PlayerControllerClass = AMyPlayerController::StaticClass();
}