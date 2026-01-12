project "LFrameApp"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    targetdir "Binaries/%{cfg.buildcfg}"
    staticruntime "off"

    targetdir ("../Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("../Binaries/Intermediates/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs
    {
        "Source",
        "%{wks.location}/LFrame/Vendor/spdlog/include",
        "%{wks.location}/LFrame/Source",
        "%{wks.location}/LFrame/Vendor",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.glm}",
    }

    links
    {
        "LFrame"
    }

    filter "system:windows"
        systemversion "latest"
        defines { "WINDOWS" }

    filter "configurations:Debug"
        defines { "LF_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "LF_RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Dist"
        defines { "LF_DIST" }
        runtime "Release"
        optimize "On"
        symbols "Off"