// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ActorComponents : ModuleRules
{
	public ActorComponents(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ActorComponents",
			"ActorComponents/Variant_Platforming",
			"ActorComponents/Variant_Platforming/Animation",
			"ActorComponents/Variant_Combat",
			"ActorComponents/Variant_Combat/AI",
			"ActorComponents/Variant_Combat/Animation",
			"ActorComponents/Variant_Combat/Gameplay",
			"ActorComponents/Variant_Combat/Interfaces",
			"ActorComponents/Variant_Combat/UI",
			"ActorComponents/Variant_SideScrolling",
			"ActorComponents/Variant_SideScrolling/AI",
			"ActorComponents/Variant_SideScrolling/Gameplay",
			"ActorComponents/Variant_SideScrolling/Interfaces",
			"ActorComponents/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
