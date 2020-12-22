workspace "GameOfTanks"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative the root folder
IncludeDir = {}

project "GameOfTanks"
	location "GameOfTanks"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "%{prj.name}/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/SFML-2.5.1/include",
	}

	libdirs
	{
		"%{prj.name}/vendor/SFML-2.5.1/lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		optimize "On"

		links
		{
			"sfml-graphics-d.lib",
			"sfml-system-d.lib",
			"sfml-window-d.lib",
			"sfml-audio-d.lib"
		}

	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "On"

		links
		{
			"sfml-graphics.lib",
			"sfml-system.lib",
			"sfml-window.lib",
			"sfml-audio.lib"
		}

	filter "configurations:Dist"
		defines "HZ_DIST"
		runtime "Release"
		optimize "On"

		links
		{
			"sfml-graphics.lib",
			"sfml-system.lib",
			"sfml-window.lib",
			"sfml-audio.lib"
		}