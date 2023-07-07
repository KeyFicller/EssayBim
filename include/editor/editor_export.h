#pragma once

#ifdef EB_BUILD_DLL_EDITOR
    #define EB_EDITOR_EXPORT           __declspec(dllexport)
    #define EB_EDITOR_STATIC_EXPORT    EB_EDITOR_EXPORT
    #define EB_EDITOR_C_EXPORT         extern "C"
#else
    #define EB_EDITOR_EXPORT           __declspec(dllimport)
    #define EB_EDITOR_STATIC_EXPORT    
    #define EB_EDITOR_C_EXPORT         extern "C"
#endif