#pragma once

#ifdef EB_BUILD_DLL_BASIC
    #define EB_BASIC_EXPORT           __declspec(dllexport)
    #define EB_BASIC_STATIC_EXPORT    EB_BASIC_EXPORT
    #define EB_BASIC_C_EXPORT         extern "C"
#else
    #define EB_BASIC_EXPORT           __declspec(dllimport)
    #define EB_BASIC_STATIC_EXPORT    
    #define EB_BASIC_C_EXPORT         extern "C"
#endif