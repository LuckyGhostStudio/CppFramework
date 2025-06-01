-- premake5.lua
workspace "LFrame"      -- 解决方案名称
    architecture "x64"  -- 体系结构
    configurations { "Debug", "Release", "Dist" }
    startproject "LFrameApp"

    flags { "MultiProcessorCompile" }

outputdir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"     -- 输出目录

-- 依赖
group "Dependencies"
    include "LFrame/Vendor/GLFW"  -- 包含 GLFW 目录
    include "LFrame/Vendor/GLAD"  -- 包含 GLAD 目录
    include "LFrame/Vendor/imgui" -- 包含 imgui 目录
group ""

include "Dependencies.lua"

group "Core"
    include "LFrame/Build-LFrame.lua"
group ""

include "LFrameApp/Build-LFrameApp.lua"