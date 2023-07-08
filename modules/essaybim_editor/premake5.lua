project "essaybim_editor"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(g_workspaceDir .. "/bin/" .. g_outputDir .. "/%{prj.name}")
    objdir(g_workspaceDir .. "/bin-int/" .. g_outputDir .. "/%{prj.name}")

    defines {
        "EB_BUILD_DLL_EDITOR",
    }

    ignoredefaultlibraries {
        "LIBCMTD"
    }

    files {
        g_includeDir.. "/editor/**.h",
        "inc/**.h",
        "src/**.cpp",
        "premake5.lua"
    }

    vpaths {
        ["include/*"] = {g_includeDir.. "/editor/**.h"}
    }

    includedirs {
        "inc",

        g_includeDir.. "/basic",
        g_includeDir.. "/event",
        g_includeDir.. "/gui",
        g_includeDir.. "/renderer",
        g_includeDir.. "/window",
        g_includeDir.. "/editor",
        g_includeDir.. "/geometry",
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} \"../../bin/" .. g_outputDir .. "/demo/\"")
    }

    links {
        "essaybim_basic",
        "essaybim_event",
        "essaybim_renderer",
        "essaybim_window",
        "essaybim_gui",
        "essaybim_geometry"
    }