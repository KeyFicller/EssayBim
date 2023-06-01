#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"

#include <string>

namespace EB
{
    /*
     * @brief  enum of modules.
     */
    enum class eModules {
        kBasic
    };

    /*
     * @brief  this class is to help file system.
     */
    class EB_EXPORT FileServer
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(FileServer)
    public:
        /*
         * @brief  constructor for FileServer.
         */
        FileServer();

        /*
         * @brief  destructor for FileServer.
         */
        ~FileServer();

    public:
        /*
         * @brief  get global filer server instance.
         * @return reference to global filer server.
         */
        static const FileServer& instance();

    public:
        /*
         * @brief    return the root path of module.
         * @param[in]    mod    module enum.
         * @return   directory of module.
         */
        std::string projectPathRoot(eModules mod) const;

        /*
         * @brief   return the root path of resources.
         * @return  directory of resources.
         */
        std::string resourcesPathRoot() const;
    };
}