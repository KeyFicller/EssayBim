project "essaybim"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(g_workspaceDir .. "/bin/" .. g_outputDir .. "/%{prj.name}")
    objdir(g_workspaceDir .. "/bin-int/" .. g_outputDir .. "/%{prj.name}")

    defines {
        "EB_BUILD_DLL",
        "_CRT_SECURE_NO_WARNINGS"
    }

    ignoredefaultlibraries {
        "LIBCMTD"
    }

    files {
        "inc/**.h",
        "include/**.h",
        "src/**.cpp",
        "premake5.lua"
    }

    includedirs {
        "inc",
        "include",

        g_includeDir.. "/basic",
        g_includeDir.. "/event",
        g_includeDir.. "/document",
        g_includeDir.. "/renderer",
        g_includeDir.. "/window",
        g_includeDir.. "/geometry",
        g_includeDir.. "/gui"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. g_outputDir .. "/demo/\"")
    }

    links {
        "essaybim_basic",
        "essaybim_event",
        "essaybim_document",
        "essaybim_renderer",
        "essaybim_window",
        "essaybim_geometry",
        "essaybim_gui"
    }