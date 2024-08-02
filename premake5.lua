workspace "Bebr Engine"
    startproject "Run"
	configurations
	{
		"Debug",
		"Release"
	}
	platforms
	{
		"Win32",
		"Win64"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.platform}"

project "Bebr.Core"
    kind "StaticLib"
    language "C++"
    
	location "%{prj.name}/Source/"
	targetdir ("%{prj.name}/Build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{prj.name}/Build/obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.hpp",
		"%{prj.name}/Source/**.inl",
		"%{prj.name}/Source/**.cpp"
	}
    
    vpaths
    {
      ["Include"] = { "../**.hpp", "../**.inl" },
      ["Source"] = { "../**.cpp" }
    }
    
    includedirs
    {
        "%{prj.name}/Source",
		"Bebr.System/Source",
		"Bebr.Window/Source",
		"Bebr.Graphics/Source"
    }
    links
    {
		"Bebr.System",
		"Bebr.Window",
		"Bebr.Graphics"
    }
	
	filter "platforms:Win32"
		architecture "x86"
        defines "WIN32"
	filter "platforms:Win64"
		architecture "x86_64"
        defines "WIN64"
	filter "configurations:Debug"
        symbols "On"
        defines "DEBUG"
	filter "configurations:Release"
        optimize "On"
        defines "RELEASE"

project "Bebr.GL"
    kind "StaticLib"
    language "C++"
    
	location "%{prj.name}/Source/"
	targetdir ("%{prj.name}/Build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{prj.name}/Build/obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.hpp",
		"%{prj.name}/Source/**.inl",
		"%{prj.name}/Source/**.cpp"
	}
    
    vpaths
    {
      ["Include"] = { "../**.hpp", "../**.inl" },
      ["Source"] = { "../**.cpp" }
    }
    
    includedirs
    {
        "%{prj.name}/Source",
		"Bebr.System/Source",
		"Bebr.Window/Source",
        "Libraries/GLEW/include"
    }
	
	filter "platforms:Win32"
		architecture "x86"
        defines "WIN32"
        libdirs { "Libraries/GLEW/x86/lib" }
	filter "platforms:Win64"
		architecture "x86_64"
        defines "WIN64"
        libdirs { "Libraries/GLEW/x64/lib" }
	filter "configurations:Debug"
        symbols "On"
        defines "DEBUG"
	filter "configurations:Release"
        optimize "On"
        defines "RELEASE"
    filter {}
        links
        {
            "Bebr.System",
            "Bebr.Window",
            "glew32.lib",
            "opengl32.lib"
        }

project "Bebr.Graphics"
    kind "StaticLib"
    language "C++"
    
	location "%{prj.name}/Source/"
	targetdir ("%{prj.name}/Build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{prj.name}/Build/obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.hpp",
		"%{prj.name}/Source/**.inl",
		"%{prj.name}/Source/**.cpp"
	}
    
    vpaths
    {
      ["Include"] = { "../**.hpp", "../**.inl" },
      ["Source"] = { "../**.cpp" }
    }
    
    includedirs
    {
        "%{prj.name}/Source",
		"Bebr.System/Source",
		"Bebr.Window/Source"
    }
    links
    {
		"Bebr.System",
		"Bebr.Window"
    }
	
	filter "platforms:Win32"
		architecture "x86"
        defines "WIN32"
	filter "platforms:Win64"
		architecture "x86_64"
        defines "WIN64"
	filter "configurations:Debug"
        symbols "On"
        defines "DEBUG"
	filter "configurations:Release"
        optimize "On"
        defines "RELEASE"

project "Bebr.System"
    kind "StaticLib"
    language "C++"
    
	location "%{prj.name}/Source/"
	targetdir ("%{prj.name}/Build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{prj.name}/Build/obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.hpp",
		"%{prj.name}/Source/**.inl",
		"%{prj.name}/Source/**.cpp"
	}
    
    vpaths
    {
      ["Include"] = { "../**.hpp", "../**.inl" },
      ["Source"] = { "../**.cpp" }
    }
    
    includedirs
    {
        "%{prj.name}/Source"
    }
    links
    {
    }
	
	filter "platforms:Win32"
		architecture "x86"
        defines "WIN32"
	filter "platforms:Win64"
		architecture "x86_64"
        defines "WIN64"
	filter "configurations:Debug"
        symbols "On"
        defines "DEBUG"
	filter "configurations:Release"
        optimize "On"
        defines "RELEASE"
    filter {}
        defines { platformDefine, configurationDefine }

project "Bebr.Window"
    kind "StaticLib"
    language "C++"
    
	location "%{prj.name}/Source/"
	targetdir ("%{prj.name}/Build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{prj.name}/Build/obj/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/Source/**.hpp",
		"%{prj.name}/Source/**.inl",
		"%{prj.name}/Source/**.cpp"
	}
    
    vpaths
    {
      ["Include"] = { "../**.hpp", "../**.inl" },
      ["Source"] = { "../**.cpp" }
    }
    
	filter "platforms:Win32"
        architecture "x86"
        defines "WIN32"
        includedirs {
            "%{prj.name}/Source",
            "Bebr.System/Source",
            "Libraries/GLFW/x86/include/GLFW"
        }
        libdirs { "Libraries/GLFW/x86/lib" }
    filter "platforms:Win64"
        architecture "x86_64"
        defines "WIN64"
        includedirs {
            "%{prj.name}/Source",
            "Bebr.System/Source",
            "Libraries/GLFW/x64/include/GLFW"
        }
        libdirs { "Libraries/GLFW/x64/lib" }
    filter "configurations:Debug"
        symbols "On"
        defines "DEBUG"
    filter "configurations:Release"
        optimize "On"
        defines "RELEASE"
	filter {}
    	links { "Bebr.System", "glfw3.lib" }

project "Run"
	kind "ConsoleApp"
	language "C++"
    
	location "%{prj.name}/Source/"
	targetdir ("%{prj.name}/Build/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{prj.name}/Build/obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.hpp",
		"%{prj.name}/Source/**.inl",
		"%{prj.name}/Source/**.cpp",
		"%{prj.name}/Source/**.glsl"
	}
    
    vpaths
    {
      ["Include"] = { "../**.hpp", "../**.inl" },
      ["Source"] = { "../**.cpp" },
      ["Shaders"] = { "../**.glsl" }
    }
    
    includedirs
    {
        "%{prj.name}/Source",
		"Bebr.System/Source",
		"Bebr.Window/Source",
		"Bebr.Graphics/Source",
		"Bebr.Core/Source",
		"Bebr.GL/Source",
        "Libraries/GLEW/include"
    }
    links
    {
		"Bebr.System",
		"Bebr.Window",
        "Bebr.GL"
    }
	
	filter "platforms:Win32"
		architecture "x86"
        defines "WIN32"
        libdirs { "Libraries/GLEW/x86/lib" }
        postbuildcommands { "copy /B /Y \"%{wks.location}Libraries\\GLEW\\x86\\bin\\glew32.dll\" \"%{cfg.targetdir}\"" }
	filter "platforms:Win64"
		architecture "x86_64"
        defines "WIN64"
        libdirs { "Libraries/GLEW/x64/lib" }
        postbuildcommands { "copy /B /Y \"%{wks.location}Libraries\\GLEW\\x64\\bin\\glew32.dll\" \"%{cfg.targetdir}\"" }
	filter "configurations:Debug"
        symbols "On"
        defines "DEBUG"
	filter "configurations:Release"
        optimize "On"
        defines "RELEASE"
