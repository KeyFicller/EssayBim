#pragma once

#ifdef EB_BUILD_DLL
    #define EB_EXPORT       __declspec(dllexport)
    #define EB_C_EXPORT     extern "C"
#else
    #define EB_EXPORT       __declspec(dllimport)
    #define EB_C_EXPORT     extern "C"
#endif