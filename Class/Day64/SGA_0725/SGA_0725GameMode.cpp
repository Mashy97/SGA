// Copyright Epic Games, Inc. All Rights Reserved.

#include "SGA_0725GameMode.h"
#include "SGA_0725Character.h"
#include "UObject/ConstructorHelpers.h"

ASGA_0725GameMode::ASGA_0725GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
