using UnrealBuildTool;

public class Meteors : ModuleRules{
    public Meteors(ReadOnlyTargetRules Target): base(Target){
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Paper2D" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
    }
}