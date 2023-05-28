project "essaybim_basic"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(g_workspaceDir .. "/bin/" .. g_outputDir .. "/%{prj.name}")
    objdir(g_workspaceDir .. "/bin-int/" .. g_outputDir .. "/%{prj.name}")

    defines {
        "EB_BUILD_DLL"
    }

    files {
        g_includeDir.. "/basic/**.h",
        "inc/**.h",
        "src/**.cpp"
    }

    vpaths {
        ["include/*"] = {g_includeDir.. "/basic/**.h"}
    }

    includedirs {
        "inc",

        g_includeDir.. "/basic",

        g_thirdDir.. "/spdlog/include"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} \"../../bin/" .. g_outputDir .. "/demo/\"")
    }