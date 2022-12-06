-- premake5.lua
workspace "Ryder"
    architecture "x64"
    startproject "Sandbox"
    configurations 
    { 
        "Debug", 
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ryder"
    location "Ryder"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.c" 
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }
    
    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "RY_PLATFORM_WINDOWS",
            "RY_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }


    filter "configurations:Debug"
        defines "RY_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RY_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "RY_DIST"
        symbols "On"
    
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.c" 
    }

    includedirs
    {
        "Ryder/vendor/spdlog/include",
        "Ryder/src"
    }

    links
    {
        "Ryder"
    }
    
    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "RY_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "RY_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RY_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "RY_DIST" 
        symbols "On"
