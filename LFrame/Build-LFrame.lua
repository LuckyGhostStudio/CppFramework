project "LFrame"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    targetdir "Binaries/%{cfg.buildcfg}"
    staticruntime "off"

    files
    {
        "Source/**.h",
        "Source/**.cpp",
        "Vendor/stb_image/**.h",
        "Vendor/stb_image/**.cpp",
    }

    includedirs         -- ���Ӱ���Ŀ¼
    {
        "Source",
        "Vendor",
        "Vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.stb_image}",
    }

    targetdir ("../Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("../Binaries/Intermediates/" .. outputdir .. "/%{prj.name}")

    filter "system:windows"
        systemversion "latest"
        defines { }

    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Dist"
        defines { "DIST" }
        runtime "Release"
        optimize "On"
        symbols "Off"