project "essaybim_renderer"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(g_workspaceDir .. "/bin/" .. g_outputDir .. "/%{prj.name}")
    objdir(g_workspaceDir .. "/bin-int/" .. g_outputDir .. "/%{prj.name}")

    defines {
        "EB_BUILD_DLL"
    }

    ignoredefaultlibraries {
        "LIBCMTD"
    }

    files {
        g_includeDir.. "/renderer/**.h",
        "inc/**.h",
        "src/**.cpp"
    }

    vpaths {
        ["include/*"] = {g_includeDir.. "/renderer/**.h"}
    }

    includedirs {
        "inc",

        g_includeDir.. "/basic",
        g_includeDir.. "/renderer",

        g_thirdDir.. "/glm",
        g_thirdDir.. "/glad/include",
        g_thirdDir.. "/glfw/include"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} \"../../bin/" .. g_outputDir .. "/demo/\"")
    }

    links {
        "essaybim_basic",

        "glad",
        "glfw"
    }