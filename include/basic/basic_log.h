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
    private:
        /*
         * @brief      constructor for log protected.
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
    };
}