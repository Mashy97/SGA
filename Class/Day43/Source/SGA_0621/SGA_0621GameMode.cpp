// Copyright Epic Games, Inc. All Rights Reserved.

#include "SGA_0621GameMode.h"
#include "SGA_0621Character.h"
#include "UObject/ConstructorHelpers.h"

ASGA_0621GameMode::ASGA_0621GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
