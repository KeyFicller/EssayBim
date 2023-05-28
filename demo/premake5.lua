project "demo"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(g_workspaceDir .. "/bin/" .. g_outputDir .. "/%{prj.name}")
    objdir(g_workspaceDir .. "/bin-int/" .. g_outputDir .. "/%{prj.name}")

    defines {

    }

    files {
        "inc/**.h",
        "src/**.cpp"
    }

    includedirs {
        "inc",
        g_includeDir.. "/basic"
    }

    links {
        "essaybim_basic"
    }

