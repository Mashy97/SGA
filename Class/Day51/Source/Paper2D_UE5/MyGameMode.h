// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameMode.generated.h"

class AMyPaperCharacter_ZD;
/**
 * 
 */
UCLASS()
class PAPER2D_UE5_API AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	AMyGameMode();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Character")
	void SetPlayerCharacter(TSubclassOf<AMyPaperCharacter_ZD> NewCharacterClass);


private:
	TSubclassOf<AMyPaperCharacter_ZD> SelectedCharacterClass;
};
