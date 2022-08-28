workspace "C-CPP_Standard_Lib"
    architecture "x64"
    startproject "Testing"

    configurations
    {
        "debug",
        "release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "C_STD_Lib"
    location "C_STD_Lib"
    kind "SharedLib"
    language "C"

    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.c"
    }

    includedirs
    {
        
    }

    filter "system:windows"
        cdialect "C11"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "F515_PLATFORM_WINDOWS",
            "F515_BUILD_DLL"
        }

    filter "system:linux"
        cdialect "C11"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "F515_PLATFORM_LINUX",
            "F515_BUILD_SO"
        }

    filter { "system:linux", "action:gmake" }
        linkoptions { "`wx-config --libs`", "-pthread" }

    filter "configurations:debug"
        defines "F515_DEBUG"
        symbols "On"

    filter "configurations:release"
        defines "F515_RELEASE"
        optimize "On"

project "CPP_STD_Lib"
    location "CPP_STD_Lib"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "C_STD_Lib/src"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "F515_PLATFORM_WINDOWS",
            "F515_BUILD_DLL"
        }

    filter "system:linux"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "F515_PLATFORM_LINUX",
            "F515_BUILD_SO"
        }

    filter { "system:linux", "action:gmake" }
        linkoptions { "`wx-config --libs`", "-pthread" }

    filter "configurations:debug"
        defines "F515_DEBUG"
        symbols "On"

    filter "configurations:release"
        defines "F515_RELEASE"
        optimize "On"

project "Testing"
    location "Testing"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "C_STD_Lib/src",
        "CPP_STD_Lib/src"
    }

    links
    {
        "C_STD_Lib",
        "CPP_STD_Lib"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "F515_PLATFORM_WINDOWS"
        }

    filter "system:linux"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "F515_PLATFORM_LINUX"
        }

    filter { "system:linux", "action:gmake" }
        linkoptions { "`wx-config --libs`", "-pthread" }

    filter "configurations:debug"
        defines "F515_DEBUG"
        symbols "On"

    filter "configurations:release"
        defines "F515_RELEASE"
        optimize "On"
