-- ����Ŀ¼
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Lucky/Vendor/GLFW/include"
IncludeDir["GLAD"] = "%{wks.location}/Lucky/Vendor/GLAD/include"
IncludeDir["ImGui"] = "%{wks.location}/Lucky/Vendor/imgui"
--IncludeDir["glm"] = "%{wks.location}/Lucky/Vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Lucky/Vendor/stb_image"

-- ��Ŀ¼
LibraryDir = {}

-- Libs
Library = {}

-- Windows
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"