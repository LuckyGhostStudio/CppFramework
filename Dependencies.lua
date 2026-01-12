-- 包含目录
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/LFrame/Vendor/GLFW/include"
IncludeDir["GLAD"] = "%{wks.location}/LFrame/Vendor/GLAD/include"
IncludeDir["ImGui"] = "%{wks.location}/LFrame/Vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/LFrame/Vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/LFrame/Vendor/stb_image"

-- 库目录
LibraryDir = {}

-- Libs
Library = {}

-- Windows
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"