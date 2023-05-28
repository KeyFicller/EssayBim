#pragma once

#include <chrono>
#include <fstream>
#include <string>

namespace EB
{
    struct ProfileResult;

    class InstrumentImpl
    {
    public:
        InstrumentImpl();

    public:
        void begin(const std::string& name, const std::string& filePath = "result.json");
        void end();
        void writeProfile(const ProfileResult& res);
        void writeHeader();
        void writeFooter();

    private:
        std::string m_CurName;             // 当前Profile的名称,也就是begin的第一个参数
        int m_ProfileCount = 0;
        std::ofstream m_OutputStream;
    };

    class InstrumentTimerImpl
    {
    public:
        explicit InstrumentTimerImpl(const std::string& name);
        explicit InstrumentTimerImpl(const char* name);
        ~InstrumentTimerImpl();

    public:
        void stop();

    private:
        std::string m_Name;
        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
        bool m_Stopped = false;
    };
}