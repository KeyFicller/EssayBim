#pragma once

#include "basic_export.h"

#include <string>

namespace EB
{
    /*
     * @brief    this class is used to define logging system.
     */
    class EB_EXPORT Log final
    {
        friend class LogImpl;
    public:
        /*
         * @biref     destructor for logger.
         */
        virtual ~Log();

    private:
        /*
         * @brief      constructor for logger protected.
         * @param[in]  name      name of logger.
         */
        explicit Log(const std::string& name);

    public:
        /*
         * @brief      get global core logger instance.
         * @return     reference to global core logger instance.
         */
        static Log& core();

        /*
         * @brief      get global core logger instance.
         * @return     reference to global core logger instance.
         */
        static Log& client();

    public:
        void trace(const char* fmt);

    private:
        /* < implement class pointer > */
        LogImpl* m_pImpl = nullptr;
    };
}