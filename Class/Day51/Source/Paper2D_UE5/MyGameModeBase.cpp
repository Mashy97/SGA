// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "MyPaperCharacter_ZD.h"
#include "UObject/ConstructorHelpers.h"

#include "Kismet/GameplayStatics.h"
#include "CharacterSelectWidget.h"


AMyGameModeBase::AMyGameModeBase()
{
	// 블루프린터 클래스를 디폴트 Pawn 클래스로 세팅하는 방법
	
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Paper2D/Characters/BP_Character"));
	//if (PlayerPawnBPClass.Class != nullptr)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
	

	static ConstructorHelpers::FClassFinder<APlayerController> ControllClass(TEXT("/Game/Paper2D/BP_MyPlayerController"));

	if (ControllClass.Class != nullptr)
	{
		PlayerControllerClass = ControllClass.Class;
	}

}

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void AMyGameModeBase::SetPlayerCharacter(TSubclassOf<AMyPaperCharacter_ZD> NewCharacterClass)
{
	if (NewCharacterClass)
	{	//GetPlayerController(const UObject* WorldContextObject, int32 PlayerIndex) 
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->Possess(GetWorld()->SpawnActor<AMyPaperCharacter_ZD>(NewCharacterClass));
		UE_LOG(LogTemp, Warning, TEXT(" SetPlayerCharacter "));

	}
	// OnPossess(APawn* InPawn)
}