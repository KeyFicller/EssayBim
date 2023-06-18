project "essaybim_gui"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(g_workspaceDir .. "/bin/" .. g_outputDir .. "/%{prj.name}")
    objdir(g_workspaceDir .. "/bin-int/" .. g_outputDir .. "/%{prj.name}")

    defines {
        "EB_BUILD_DLL",
        "USE_GLM_IN_MODULE"
    }

    ignoredefaultlibraries {
        "LIBCMTD"
    }

    files {
        g_includeDir.. "/gui/**.h",
        "inc/**.h",
        "src/**.cpp",
        "premake5.lua"
    }

    vpaths {
        ["include/*"] = {g_includeDir.. "/gui/**.h"}
    }

    includedirs {
        "inc",

        g_includeDir.. "/basic",
        g_includeDir.. "/event",
        g_includeDir.. "/gui",
        g_includeDir.. "/renderer",
        g_includeDir.. "/window",

        g_thirdDir.. "/glm",
        g_thirdDir.. "/imgui",
        g_thirdDir.. "/glad/include",
        g_thirdDir.. "/glfw/include",
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

        "imgui",
        "glad",
        "glfw"
    }