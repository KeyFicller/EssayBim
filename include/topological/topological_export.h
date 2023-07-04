#pragma once

#ifdef EB_BUILD_DLL_TOPOLOGICAL
    #define EB_TOPOLOGICAL_EXPORT           __declspec(dllexport)
    #define EB_TOPOLOGICAL_STATIC_EXPORT    EB_TOPOLOGICAL_EXPORT
    #define EB_TOPOLOGICAL_C_EXPORT         extern "C"
#else
    #define EB_TOPOLOGICAL_EXPORT           __declspec(dllimport)
    #define EB_TOPOLOGICAL_STATIC_EXPORT    
    #define EB_TOPOLOGICAL_C_EXPORT         extern "C"
#endif