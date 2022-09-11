workspace "YTStreams-iostream"
    architecture "x64"
    startproject "Testing"

    configurations
    {
        "debug",
        "release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "iostream"
    location "iostream"
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
        buildoptions { "`wx-config --cxxflags`", "-ffreestanding" }

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
        "iostream/src"
    }

    links
    {
        "iostream"
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
        buildoptions { "`wx-config --cxxflags`", "-ffreestanding" }

    filter "configurations:debug"
        defines "F515_DEBUG"
        symbols "On"

    filter "configurations:release"
        defines "F515_RELEASE"
        optimize "On"
