#pragma once

#ifdef EB_BUILD_DLL_GUI
    #define EB_GUI_EXPORT           __declspec(dllexport)
    #define EB_GUI_STATIC_EXPORT    EB_GUI_EXPORT
    #define EB_GUI_C_EXPORT         extern "C"
#else
    #define EB_GUI_EXPORT           __declspec(dllimport)
    #define EB_GUI_STATIC_EXPORT    
    #define EB_GUI_C_EXPORT         extern "C"
#endif