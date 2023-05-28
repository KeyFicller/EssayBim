#include "basic_log.h"

#include "basic_log_impl.h"

namespace EB
{
    Log::~Log()
    {
        delete m_pImpl;
        m_pImpl = nullptr;
    }

    Log::Log(const std::string& name)
    {
        m_pImpl = new LogImpl(name);
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

    void Log::trace(const char* fmt)
    {
        return m_pImpl->trace(fmt);
    }

}