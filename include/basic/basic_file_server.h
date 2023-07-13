#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"

#include <string>
#include <windows.h>

namespace EB
{
    /**
     * @brief  enum of modules.
     */
    enum class eModules {
        /** < basic module > */
        kBasic,

        /** < document module, manage camera view and data > */
        kDocument,

        /** < event module, mostly defines > */
        kEvent,

        /** < geometry module, topological geometry > */
        kGeometry,

        /** < gui module, wrapper imgui > */
        kGui,

        /** < renderer module > */
        kRenderer,

        /** < window module, wrapper glfw window > */
        kWindow
    };

    /**
     * @brief  this class is to help file system.
     */
    class EB_BASIC_EXPORT FileServer
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(FileServer)
    public:
        /**
         * @brief  constructor for FileServer.
         */
        FileServer();

        /**
         * @brief  destructor for FileServer.
         */
        ~FileServer();

    public:
        /**
         * @brief    return the root path of module.
         * @param[in]    mod    module enum.
         * @return   directory of module.
         */
        static std::string projectPathRoot(eModules mod);

        /**
         * @brief   return the root path of resources.
         * @return  directory of resources.
         */
        static std::string resourcesPathRoot();

        /**
         * @brief   read string from file path.
         * @param[in]   filePath     file location.
         * @return    string read out.
         */
        static std::string readFromFilePath(const std::string& filePath);

        /**
         * @brief   get file name of file path.
         * @param[in]   filePath     file location.
         * @return  file name without suffix.
         */
        static std::string fileNameOfPath(const std::string& filePath);

        /**
         * @brief   get open file path.
         * @param[in]   filter       fmt of file filter.
         * @param[in]   owner        owner of modal window.
         */
        static std::string openFile(const char* filter, HWND owner = nullptr);

        /**
         * @brief   get save file path.
         * @param[in]   filter       fmt of file filter.
         * @param[in]   owner        owner of modal window.
         */
        static std::string saveFile(const char* filter, HWND owner = nullptr);
    };
}