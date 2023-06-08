project "demo"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(g_workspaceDir .. "/bin/" .. g_outputDir .. "/%{prj.name}")
    objdir(g_workspaceDir .. "/bin-int/" .. g_outputDir .. "/%{prj.name}")

    defines {
        "USE_GLM_IN_MODULE"
    }

    files {
        "inc/**.h",
        "src/**.cpp"
    }

    includedirs {
        g_includeDir.. "/basic",
        g_includeDir.. "/renderer",

        g_thirdDir.. "/glm"
    }

    links {
        "essaybim_basic",
        "essaybim_renderer"
    }

