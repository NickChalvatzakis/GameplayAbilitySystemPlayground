using UnrealBuildTool;

public class ExtendedGas : ModuleRules
{
	public ExtendedGas(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks", "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { "EnhancedInput"});

		PublicIncludePaths.Add("ExtendedGas/");
        PublicIncludePaths.Add("ExtendedGas/Public");
	}
}
