#pragma once

#ifdef EB_BUILD_DLL_WINDOW
    #define EB_WINDOW_EXPORT           __declspec(dllexport)
    #define EB_WINDOW_STATIC_EXPORT    EB_WINDOW_EXPORT
    #define EB_WINDOW_C_EXPORT         extern "C"
#else
    #define EB_WINDOW_EXPORT           __declspec(dllimport)
    #define EB_WINDOW_STATIC_EXPORT    
    #define EB_WINDOW_C_EXPORT         extern "C"
#endif