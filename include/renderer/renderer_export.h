#pragma once

#ifdef EB_BUILD_DLL_RENDERER
    #define EB_RENDERER_EXPORT           __declspec(dllexport)
    #define EB_RENDERER_STATIC_EXPORT    EB_RENDERER_EXPORT
    #define EB_RENDERER_C_EXPORT         extern "C"
#else
    #define EB_RENDERER_EXPORT           __declspec(dllimport)
    #define EB_RENDERER_STATIC_EXPORT    
    #define EB_RENDERER_C_EXPORT         extern "C"
#endif