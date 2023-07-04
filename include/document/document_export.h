#pragma once

#ifdef EB_BUILD_DLL_DOCUMENT
    #define EB_DOCUMENT_EXPORT           __declspec(dllexport)
    #define EB_DOCUMENT_STATIC_EXPORT    EB_DOCUMENT_EXPORT
    #define EB_DOCUMENT_C_EXPORT         extern "C"
#else
    #define EB_DOCUMENT_EXPORT           __declspec(dllimport)
    #define EB_DOCUMENT_STATIC_EXPORT    
    #define EB_DOCUMENT_C_EXPORT         extern "C"
#endif