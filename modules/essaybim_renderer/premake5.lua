project "essaybim_renderer"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(g_workspaceDir .. "/bin/" .. g_outputDir .. "/%{prj.name}")
    objdir(g_workspaceDir .. "/bin-int/" .. g_outputDir .. "/%{prj.name}")

    defines {
        "EB_BUILD_DLL_RENDERER",
        "USE_GLM_IN_MODULE"
    }

    ignoredefaultlibraries {
        "LIBCMTD"
    }

    files {
        g_includeDir.. "/renderer/**.h",
        "inc/**.h",
        "src/**.cpp",
        "premake5.lua"
    }

    vpaths {
        ["include/*"] = {g_includeDir.. "/renderer/**.h"}
    }

    includedirs {
        "inc",

        g_includeDir.. "/basic",
        g_includeDir.. "/renderer",
        g_includeDir.. "/geometry",

        g_thirdDir.. "/glm",
        g_thirdDir.. "/glad/include",
        g_thirdDir.. "/glfw/include",
        g_thirdDir.. "/stb"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} \"../../bin/" .. g_outputDir .. "/demo/\"")
    }

    links {
        "essaybim_basic",
        "essaybim_geometry",

        "glad",
        "glfw"
    }