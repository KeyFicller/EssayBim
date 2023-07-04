#pragma once

#ifdef EB_BUILD_DLL_GEOMETRY
    #define EB_GEOMETRY_EXPORT           __declspec(dllexport)
    #define EB_GEOMETRY_STATIC_EXPORT    EB_GEOMETRY_EXPORT
    #define EB_GEOMETRY_C_EXPORT         extern "C"
#else
    #define EB_GEOMETRY_EXPORT           __declspec(dllimport)
    #define EB_GEOMETRY_STATIC_EXPORT    
    #define EB_GEOMETRY_C_EXPORT         extern "C"
#endif