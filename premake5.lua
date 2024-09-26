workspace "Ziggi"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Ziggi/vendor/GLFW/include"

include  "Ziggi/vendor/GLFW"

project "Ziggi"
	location "Ziggi"
	kind "SharedLib"
	language "C++"

	targetdir("bin/"..outputdir.."/%{prj.name}")
	objdir("bin-int/"..outputdir.."/%{prj.name}")

	pchheader "zgpch.h"
	pchsource "Ziggi/src/zgpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

	defines
	{
		"ZG_PLATFORM_WINDOWS",
		"ZG_BUILD_DLL"
	}

	postbuildcommands
	{
		"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/"
	}

	filter "configurations:Debug"
		defines "ZG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZG_DIST"
		symbols "On"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/"..outputdir.."/%{prj.name}")
	objdir("bin-int/"..outputdir.."/%{prj.name}")

	pchheader "zgpch.h"
	pchsource "Sandbox/src/sbpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Ziggi/vendor/spdlog/include",
		"Ziggi/src"
	}

	links
	{
		"Ziggi"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"ZG_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "ZG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZG_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZG_DIST"
		symbols "On"