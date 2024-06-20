// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MySaveGame.h"
#include "Move_UI.generated.h"

/**
 * 
 */
UCLASS()
class SGA_0613_API UMove_UI : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UMove_UI();

	UFUNCTION(BlueprintCallable, Category = MyGame)
	void OnSaveGame(FString slotname, UClass* target);

	UFUNCTION(BlueprintCallable, Category = MyGame)
	void OnLoadGame(FString slotname, UClass* target);
};
