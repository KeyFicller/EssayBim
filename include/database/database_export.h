#pragma once

#ifdef EB_BUILD_DLL_DATABASE
    #define EB_DATABASE_EXPORT           __declspec(dllexport)
    #define EB_DATABASE_STATIC_EXPORT    EB_DATABASE_EXPORT
    #define EB_DATABASE_C_EXPORT         extern "C"
#else
    #define EB_DATABASE_EXPORT           __declspec(dllimport)
    #define EB_DATABASE_STATIC_EXPORT    
    #define EB_DATABASE_C_EXPORT         extern "C"
#endif