#include "basic_instrument_impl.h"

#include "basic_instrument.h"

#include <algorithm>
#include <thread>

namespace EB
{

    InstrumentImpl::InstrumentImpl()
        : m_ProfileCount(0)
    {

    }

    void InstrumentImpl::begin(const std::string& name, const std::string& filePath /*= "result.json"*/)
    {
        m_OutputStream.open(filePath);
        writeHeader();
        m_CurName = name;
    }

    void InstrumentImpl::end()
    {
        writeFooter();
        m_OutputStream.close();
        m_CurName = "";
        m_ProfileCount = 0;
    }

    void InstrumentImpl::writeProfile(const ProfileResult& res)
    {
        if (m_ProfileCount++ > 0) {
            m_OutputStream << ",";
        }

        std::replace(m_CurName.begin(), m_CurName.end(), '"', '\'');
        m_OutputStream << "{";
        m_OutputStream << "\"cat\":\"function\",";
        m_OutputStream << "\"dur\":" << (res.EndTime - res.StartTime) << ",";
        m_OutputStream << "\"name\":\"" << m_CurName << "\",";
        m_OutputStream << "\"ph\":\"X\",";
        m_OutputStream << "\"pid\":0,";
        m_OutputStream << "\"tid\":" << res.ThreadId << ",";
        m_OutputStream << "\"ts\":" << res.StartTime;
        m_OutputStream << "}";

        m_OutputStream.flush();
    }

    void InstrumentImpl::writeHeader()
    {
        m_OutputStream << "{\"otherData\": {},\"traceEvents\":[";
        m_OutputStream.flush();
    }

    void InstrumentImpl::writeFooter()
    {
        m_OutputStream << "]}";
        m_OutputStream.flush();
    }

    InstrumentTimerImpl::InstrumentTimerImpl(const std::string& name)
        : m_Name(name), m_Stopped(false)
    {
        m_StartTime = std::chrono::high_resolution_clock::now();
    }


    InstrumentTimerImpl::InstrumentTimerImpl(const char* name)
        : InstrumentTimerImpl(std::string(name))
    {

    }

    InstrumentTimerImpl::~InstrumentTimerImpl()
    {
        if (!m_Stopped) {
            stop();
        }
    }

    void InstrumentTimerImpl::stop()
    {
        auto endTime = std::chrono::high_resolution_clock::now();
        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTime).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch().count();

        unsigned int threadID = static_cast<unsigned int>(std::hash<std::thread::id>{}(std::this_thread::get_id()));
        Instrument::instance().writeProfile({ m_Name, start, end, threadID });

        m_Stopped = true;
    }

}