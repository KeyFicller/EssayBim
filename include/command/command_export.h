#pragma once

#ifdef EB_BUILD_DLL_COMMAND
    #define EB_COMMAND_EXPORT           __declspec(dllexport)
    #define EB_COMMAND_STATIC_EXPORT    EB_COMMAND_EXPORT
    #define EB_COMMAND_C_EXPORT         extern "C"
#else
    #define EB_COMMAND_EXPORT           __declspec(dllimport)
    #define EB_COMMAND_STATIC_EXPORT    
    #define EB_COMMAND_C_EXPORT         extern "C"
#endif