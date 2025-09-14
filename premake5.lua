workspace "MDD2"
	architecture "x64"


	configurations 
	{ 
		"Debug", 
		"Release", 
		"Dist" 
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MDD2"
	location "MDD2"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files 
	{ 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp" 
	}

	includedirs 
	{ 
		"%{prj.name}/vendor/spdlog/include",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"
		buildoptions { "/utf-8" }  

		defines 
		{ 
			"MDD_PLATFORM_WINDOWS",
			"MDD_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "MDD2_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "MDD2_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "MDD2_DIST"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files 
	{ 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp" 
	}

	includedirs 
	{ 
		"MDD2/vendor/spdlog/include",
		"MDD2/src"
	}

	links 
	{ 
		"MDD2" 
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"
		buildoptions { "/utf-8" }  
		
		defines 
		{ 
			"MDD_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "MDD2_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "MDD2_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "MDD2_DIST"
		optimize "on"
