// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "MyPlayerController.h"
#include "MyPaperCharacter_ZD.h"
#include "UObject/ConstructorHelpers.h"

#include "Kismet/GameplayStatics.h"
#include "CharacterSelectWidget.h"


AMyGameMode::AMyGameMode()
{

	
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Paper2D/Characters/BP_Character_ZD"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	

	static ConstructorHelpers::FClassFinder<APlayerController> ControllClass(TEXT("/Game/Paper2D/BP_MyPlayerController"));

	if (ControllClass.Class != nullptr)
	{
		PlayerControllerClass = ControllClass.Class;
	}
}


void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();
	// 초기 캐릭터 선택 로직
	if (SelectedCharacterClass)
	{
		DefaultPawnClass = SelectedCharacterClass;
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->Possess(GetWorld()->SpawnActor<AMyPaperCharacter_ZD>(SelectedCharacterClass));
	}
}

void AMyGameMode::SetPlayerCharacter(TSubclassOf<AMyPaperCharacter_ZD> NewCharacterClass)
{
	SelectedCharacterClass = NewCharacterClass;
}
