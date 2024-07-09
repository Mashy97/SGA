// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Basic_3rd_DJump : ModuleRules
{
	public Basic_3rd_DJump(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
