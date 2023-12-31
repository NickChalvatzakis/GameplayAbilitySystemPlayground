// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class StretchyUnderdog : ModuleRules
{
	public StretchyUnderdog(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "ExtendedGas", "GameplayAbilities", "GameplayTags", "GameplayTasks", "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { "EnhancedInput", "EnhancedInput"});

		PublicIncludePaths.Add("StretchyUnderdog/");
	}
}
