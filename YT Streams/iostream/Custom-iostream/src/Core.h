#ifdef F515_PLATFORM_WINDOWS
    #ifdef F515_BUILD_DLL
        #ifndef FROSTY515_API
            #define FROSTY515_API __declspec(dllexport)
        #endif /* FROSTY515_API */
    #else
        #ifndef FROSTY515_API
            #define FROSTY515_API __declspec(dllimport)
        #endif /* FROSTY515_API */
    #endif /* F515_BUILD_DLL */
#else
    #ifdef F515_PLATFORM_LINUX
        #ifdef F515_BUILD_SO
            #ifndef FROSTY515_API
                #define FROSTY515_API 
            #endif /* FROSTY515_API */
        #else
            #ifndef FROSTY515_API
                #define FROSTY515_API 
            #endif /* FROSTY515_API */
        #endif /* F515_BUILD_SO */
    #else
        #error Only Windows and Linux are supported
    #endif /* F515_PLATFORM_LINUX */
#endif /* F515_PLATFORM_WINDOWS */