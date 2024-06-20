// Copyright Epic Games, Inc. All Rights Reserved.

#include "SGA_0613GameMode.h"
#include "SGA_0613Character.h"

ASGA_0613GameMode::ASGA_0613GameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ASGA_0613Character::StaticClass();	
}
