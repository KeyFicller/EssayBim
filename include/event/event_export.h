#pragma once

#ifdef EB_BUILD_DLL_EVENT
    #define EB_EVENT_EXPORT           __declspec(dllexport)
    #define EB_EVENT_STATIC_EXPORT    EB_EVENT_EXPORT
    #define EB_EVENT_C_EXPORT         extern "C"
#else
    #define EB_EVENT_EXPORT           __declspec(dllimport)
    #define EB_EVENT_STATIC_EXPORT    
    #define EB_EVENT_C_EXPORT         extern "C"
#endif