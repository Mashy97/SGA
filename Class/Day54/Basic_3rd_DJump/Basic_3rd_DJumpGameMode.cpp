// Copyright Epic Games, Inc. All Rights Reserved.

#include "Basic_3rd_DJumpGameMode.h"
#include "Basic_3rd_DJumpCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABasic_3rd_DJumpGameMode::ABasic_3rd_DJumpGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
