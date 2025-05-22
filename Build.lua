-- premake5.lua
workspace "CppFramework"        -- �����������
    architecture "x64"          -- ��ϵ�ṹ
    configurations { "Debug", "Release", "Dist" }
    startproject "App"

    flags { "MultiProcessorCompile" }

outputdir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"     -- ���Ŀ¼

-- ����
group "Dependencies"
    include "Core/Vendor/GLFW"  -- ���� GLFW Ŀ¼
    include "Core/Vendor/GLAD"  -- ���� GLAD Ŀ¼
    include "Core/Vendor/imgui" -- ���� imgui Ŀ¼
group ""

include "Dependencies.lua"

group "Core"
    include "Core/Build-Core.lua"
group ""

include "App/Build-App.lua"