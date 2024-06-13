// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SGA_0613 : ModuleRules
{
	public SGA_0613(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Paper2D" });
	}
}
