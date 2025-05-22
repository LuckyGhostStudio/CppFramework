-- premake5.lua
workspace "CppFramework"        -- 解决方案名称
    architecture "x64"          -- 体系结构
    configurations { "Debug", "Release", "Dist" }
    startproject "App"

    flags { "MultiProcessorCompile" }

outputdir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"     -- 输出目录

-- 依赖
group "Dependencies"
    include "Core/Vendor/GLFW"  -- 包含 GLFW 目录
    include "Core/Vendor/GLAD"  -- 包含 GLAD 目录
    include "Core/Vendor/imgui" -- 包含 imgui 目录
group ""

include "Dependencies.lua"

group "Core"
    include "Core/Build-Core.lua"
group ""

include "App/Build-App.lua"