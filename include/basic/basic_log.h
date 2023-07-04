#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"

#include <string>

namespace EB
{
    /**
     * @brief    this class is used to define logging system.
     */
    class EB_BASIC_EXPORT Log final
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(Log)
    public:
        /**
         * @biref     destructor for logger.
         */
        ~Log();

    private:
        /**
         * @brief      constructor for logger protected.
         * @param[in]  name      name of logger.
         */
        explicit Log(const std::string& name);

    public:
        /**
         * @brief      get global core logger instance.
         * @return     reference to global core logger instance.
         */
        static Log& core();

        /**
         * @brief      get global core logger instance.
         * @return     reference to global core logger instance.
         */
        static Log& client();

    public:
        /**
         * @breif        format logging at level trace.
         * @param[in]    fmt       format string.
         * @param[in]    ...       arguments.
         */
        void trace(const char* fmt, ...);

        /**
         * @breif        format logging at level info.
         * @param[in]    fmt       format string.
         * @param[in]    ...       arguments.
         */
        void info(const char* fmt, ...);

        /**
         * @breif        format logging at level warn.
         * @param[in]    fmt       format string.
         * @param[in]    ...       arguments.
         */
        void warn(const char* fmt, ...);

        /**
         * @breif        format logging at level error.
         * @param[in]    fmt       format string.
         * @param[in]    ...       arguments.
         */
        void error(const char* fmt, ...);

        /**
         * @breif        format logging at level critical.
         * @param[in]    fmt       format string.
         * @param[in]    ...       arguments.
         */
        void critical(const char* fmt, ...);
    };
}

#define EB_CORE_TRACE(...)             ::EB::Log::core().trace(__VA_ARGS__)
#define EB_CORE_INFO(...)              ::EB::Log::core().info(__VA_ARGS__)
#define EB_CORE_WARN(...)              ::EB::Log::core().warn(__VA_ARGS__)
#define EB_CORE_ERROR(...)             ::EB::Log::core().error(__VA_ARGS__)
#define EB_CORE_CRITICAL(...)          ::EB::Log::core().critical(__VA_ARGS__)

#define EB_CLIENT_TRACE(...)           ::EB::Log::client().trace(__VA_ARGS__)
#define EB_CLIENT_INFO(...)            ::EB::Log::client().info(__VA_ARGS__)
#define EB_CLIENT_WARN(...)            ::EB::Log::client().warn(__VA_ARGS__)
#define EB_CLIENT_ERROR(...)           ::EB::Log::client().error(__VA_ARGS__)
#define EB_CLIENT_CRITICAL(...)        ::EB::Log::client().critical(__VA_ARGS__)