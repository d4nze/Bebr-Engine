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
	filter "platforms:Win64"
		architecture "x86_64"

	filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
	filter "configurations:Release"
      defines { "RELEASE" }
      optimize "On"

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
	filter "platforms:Win64"
		architecture "x86_64"

	filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
	filter "configurations:Release"
      defines { "RELEASE" }
      optimize "On"

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
	filter "platforms:Win64"
		architecture "x86_64"

	filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
	filter "configurations:Release"
      defines { "RELEASE" }
      optimize "On"

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
        includedirs {
            "%{prj.name}/Source",
            "Bebr.System/Source",
            "Libraries/GLFW/x86/include/GLFW/"
        }
        libdirs { "Libraries/GLFW/x86/lib/" }

    filter "platforms:Win64"
        architecture "x86_64"
        includedirs {
            "%{prj.name}/Source",
            "Bebr.System/Source",
            "Libraries/GLFW/x64/include/GLFW/"
        }
        libdirs { "Libraries/GLFW/x64/lib/" }
	
	filter {}
    	links { "Bebr.System", "glfw3.lib" }

	filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
	filter "configurations:Release"
      defines { "RELEASE" }
      optimize "On"

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
		"Bebr.Graphics/Source",
		"Bebr.Core/Source"
    }
    links
    {
		"Bebr.System",
		"Bebr.Window"
    }
	
	filter "platforms:Win32"
		architecture "x86"
	filter "platforms:Win64"
		architecture "x86_64"

	filter "configurations:Debug"
      defines "DEBUG"
      symbols "On"
	filter "configurations:Release"
      defines "RELEASE"
      optimize "On"
