project "rebuild"
    kind "StaticLib"
	language "C++"
    cppdialect "C++17"

	targetdir(g_workspaceDir .. "/bin/" .. g_outputDir .. "/%{prj.name}")
    objdir(g_workspaceDir .. "/bin-int/" .. g_outputDir .. "/%{prj.name}")

	postbuildcommands {
        "cd ..",
		"call build.bat"
	}