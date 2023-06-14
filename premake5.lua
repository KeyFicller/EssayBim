-- custom variables
g_workspaceDir = os.getcwd()
g_outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
g_includeDir = g_workspaceDir .. "/include"
g_thirdDir = g_workspaceDir .. "/third"
print("g_workspaceDir: " .. g_workspaceDir)
print("g_outputDir: " .. g_outputDir)

workspace "EassyBim"
	configurations {"Debug", "Release"}
	filter "system:windows"
		platforms {"x64"}

	filter "configurations: Debug"
		symbols "On"
	filter "configurations: Release"
		symbols "On"

include "third"
include "modules"
include "resources"
include "essaybim"
include "demo"