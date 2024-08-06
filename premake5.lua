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

project "Bebr.GL"
    kind "StaticLib"
    language "C++"
    
	location "%{prj.name}/Source/"
	targetdir "%{prj.name}/Build/bin/%{outputdir}/%{prj.name}"
    objdir "%{prj.name}/Build/obj/%{outputdir}/%{prj.name}"

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
        libdirs "Libraries/GLEW/x86/lib"
	filter "platforms:Win64"
		architecture "x86_64"
        defines "WIN64"
        libdirs "Libraries/GLEW/x64/lib"
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

project "Bebr.GUI"
    kind "StaticLib"
    language "C++"
    
	location "%{prj.name}/Source/"
	targetdir "%{prj.name}/Build/bin/%{outputdir}/%{prj.name}"
    objdir "%{prj.name}/Build/obj/%{outputdir}/%{prj.name}"

	files
	{
		"%{prj.name}/Source/**.hpp",
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
        "Bebr.GL/Source",
        "ImGui/Source",
        "Libraries/GLEW/include"
    }
    links
    {
        "Bebr.System",
        "Bebr.GL",
        "ImGui"
    }
	
	filter "platforms:Win32"
		architecture "x86"
        defines "WIN32"
        includedirs "Libraries/GLFW/x86/include/GLFW"
        libdirs {
            "Libraries/GLFW/x86/lib",
            "Libraries/GLEW/x86/lib"
        }
	filter "platforms:Win64"
		architecture "x86_64"
        defines "WIN64"
        includedirs "Libraries/GLFW/x64/include/GLFW"
        libdirs {
            "Libraries/GLFW/x64/lib",
            "Libraries/GLEW/x64/lib"
        }
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
	targetdir "%{prj.name}/Build/bin/%{outputdir}/%{prj.name}"
    objdir "%{prj.name}/Build/obj/%{outputdir}/%{prj.name}"

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
    
    includedirs "%{prj.name}/Source"
	
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

project "Bebr.Window"
    kind "StaticLib"
    language "C++"
    
	location "%{prj.name}/Source/"
	targetdir "%{prj.name}/Build/bin/%{outputdir}/%{prj.name}"
    objdir "%{prj.name}/Build/obj/%{outputdir}/%{prj.name}"
	
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
    includedirs {
        "%{prj.name}/Source",
        "Bebr.System/Source"
    }
    
	filter "platforms:Win32"
        architecture "x86"
        defines "WIN32"
        includedirs "Libraries/GLFW/x86/include/GLFW"
        libdirs "Libraries/GLFW/x86/lib"
    filter "platforms:Win64"
        architecture "x86_64"
        defines "WIN64"
        includedirs "Libraries/GLFW/x64/include/GLFW"
        libdirs "Libraries/GLFW/x64/lib"
    filter "configurations:Debug"
        symbols "On"
        defines "DEBUG"
    filter "configurations:Release"
        optimize "On"
        defines "RELEASE"
	filter {}
    	links { "Bebr.System", "glfw3.lib" }

project "ImGui"
    kind "StaticLib"
    language "C++"
    
	location "%{prj.name}/Source/"
	targetdir "%{prj.name}/Build/bin/%{outputdir}/%{prj.name}"
    objdir "%{prj.name}/Build/obj/%{outputdir}/%{prj.name}"

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}
    
    vpaths
    {
      ["Include"] = { "../**.h", "../**.inl" },
      ["Source"] = { "../**.cpp" }
    }
    
    includedirs
    {
        "%{prj.name}/Source",
        "Libraries/GLEW/include"
    }
	
	filter "platforms:Win32"
		architecture "x86"
        defines "WIN32"
        includedirs "Libraries/GLFW/x86/include"
        libdirs
        {
            "Libraries/GLFW/x86/lib",
            "Libraries/GLEW/x86/lib"
        }
	filter "platforms:Win64"
		architecture "x86_64"
        defines "WIN64"
        includedirs "Libraries/GLFW/x64/include"
        libdirs
        {
            "Libraries/GLFW/x64/lib",
            "Libraries/GLEW/x64/lib"
        }
	filter "configurations:Debug"
        symbols "On"
        defines "DEBUG"
	filter "configurations:Release"
        optimize "On"
        defines "RELEASE"

project "Run"
	language "C++"
    
	location "%{prj.name}/Source/"
	targetdir "%{prj.name}/Build/bin/%{outputdir}/%{prj.name}"
    objdir "%{prj.name}/Build/obj/%{outputdir}/%{prj.name}"

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
		"Bebr.GL/Source",
		"Bebr.GUI/Source",
		"Bebr.System/Source",
		"Bebr.Window/Source"
    }
    links
    {
		"Bebr.System",
		"Bebr.Window",
        "Bebr.GL",
        "Bebr.GUI"
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
	    kind "ConsoleApp"
	filter "configurations:Release"
        optimize "On"
        defines "RELEASE"
	    kind "WindowedApp"
