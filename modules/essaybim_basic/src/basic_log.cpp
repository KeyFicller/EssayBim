#include "basic_log.h"

#include "basic_log_impl.h"
#include <vadefs.h>

namespace EB
{
    Log::~Log()
    {
        EB_IMPL.reset();
    }

    Log::Log(const std::string& name)
    {
        EB_IMPL = createScoped<LogImpl>(name);
    }

    Log& Log::core()
    {
        static Log instance("Core");
        return instance;
    }

    Log& Log::client()
    {
        static Log instance("Client");
        return instance;
    }

    void Log::trace(const char* fmt, ...)
    {
        va_list _args;
        __crt_va_start(_args, fmt);
        char buff[256];
        _vsprintf_s_l(buff, 256, fmt, 0, _args);
        __crt_va_end(_args);
        return EB_IMPL->trace(buff);
    }

    void Log::info(const char* fmt, ...)
    {
        va_list _args;
        __crt_va_start(_args, fmt);
        char buff[256];
        _vsprintf_s_l(buff, 256, fmt, 0, _args);
        __crt_va_end(_args);
        return EB_IMPL->info(buff);
    }

    void Log::warn(const char* fmt, ...)
    {
        va_list _args;
        __crt_va_start(_args, fmt);
        char buff[256];
        _vsprintf_s_l(buff, 256, fmt, 0, _args);
        __crt_va_end(_args);
        return EB_IMPL->warn(buff);
    }

    void Log::error(const char* fmt, ...)
    {
        va_list _args;
        __crt_va_start(_args, fmt);
        char buff[256];
        _vsprintf_s_l(buff, 256, fmt, 0, _args);
        __crt_va_end(_args);
        return EB_IMPL->error(buff);
    }

    void Log::critical(const char* fmt, ...)
    {
        va_list _args;
        __crt_va_start(_args, fmt);
        char buff[256];
        _vsprintf_s_l(buff, 256, fmt, 0, _args);
        __crt_va_end(_args);
        return EB_IMPL->critical(buff);
    }

}