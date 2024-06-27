// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "MyPaperCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMyGameModeBase::AMyGameModeBase()
{
	// ��������� Ŭ������ ����Ʈ Pawn Ŭ������ �����ϴ� ���
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/BP_MyChar"));	
		
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// ��������� Ŭ������ ����Ʈ PlayerController Ŭ������ �����ϴ� ���
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/BP_MyController"));
	
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}

	//�Ϲ� C++ Ŭ������  �����ϴ� ���
	//DefaultPawnClass = AMyPaperCharacter::StaticClass();
	//PlayerControllerClass = AMyPlayerController::StaticClass();
}