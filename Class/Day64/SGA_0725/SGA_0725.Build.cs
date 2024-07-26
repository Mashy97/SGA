// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SGA_0725 : ModuleRules
{
	public SGA_0725(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
