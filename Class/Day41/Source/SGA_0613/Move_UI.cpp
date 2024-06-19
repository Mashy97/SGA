// Fill out your copyright notice in the Description page of Project Settings.


#include "Move_UI.h"

UMove_UI::UMove_UI()
{
}

void UMove_UI::OnSaveGame(FString slotname, UClass* target)
{
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

		SaveGameInstance->GameTitle = TEXT("Test Game Title");
		SaveGameInstance->CharacterName = TEXT("Test Character Name");
		SaveGameInstance->Life = 50;

		UGameplayStatics::SaveGameToSlot(SaveGameInstance, slotname, 0);

}

void UMove_UI::OnLoadGame(FString slotname, UClass* target)
{
	UMySaveGame* LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(*slotname, 0));

	if (LoadGameInstance) {
		FString GameTitle = LoadGameInstance->GameTitle;
		FString CharacterName = LoadGameInstance->CharacterName;
		int32 Life = LoadGameInstance->Life;
	
	}
		UGameplayStatics::SaveGameToSlot(LoadGameInstance, slotname, 0);

}
