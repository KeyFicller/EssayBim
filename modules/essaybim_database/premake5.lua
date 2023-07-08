project "essaybim_database"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(g_workspaceDir .. "/bin/" .. g_outputDir .. "/%{prj.name}")
    objdir(g_workspaceDir .. "/bin-int/" .. g_outputDir .. "/%{prj.name}")

    defines {
        "EB_BUILD_DLL_DATABASE",
        "_CRT_SECURE_NO_WARNINGS",
        "USE_GLM_IN_MODULE"
    }

    ignoredefaultlibraries {
        "LIBCMTD"
    }

    files {
        g_includeDir.. "/database/**.h",
        "inc/**.h",
        "src/**.cpp"
    }

    vpaths {
        ["include/*"] = {g_includeDir.. "/database/**.h"}
    }

    includedirs {
        "inc",

        g_includeDir.. "/basic",
        g_includeDir.. "/geometry",
        g_includeDir.. "/database",

        g_thirdDir.. "/libigl/include",
        g_thirdDir.. "/eigen",
        g_thirdDir.. "/glm"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} \"../../bin/" .. g_outputDir .. "/demo/\"")
    }

    links {
        "essaybim_basic",
        "essaybim_geometry"
    }