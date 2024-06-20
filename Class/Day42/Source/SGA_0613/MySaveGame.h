// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"


/**
 * 
 */
UCLASS()
class SGA_0613_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()
public:


		UPROPERTY(VisibleAnywhere, Category = MyUI)
		FString GameTitle;

		UPROPERTY(VisibleAnywhere, Category = MyGame)
		FString CharacterName;

		UPROPERTY(VisibleAnywhere, Category = MyGame)
		int32 Life;
};
