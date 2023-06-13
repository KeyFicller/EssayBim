#include "basic_instrument.h"

#include "basic_instrument_impl.h"

namespace EB
{
    Instrument::Instrument()
    {
        EB_IMPL = createScoped<InstrumentImpl>();
    }

    Instrument& Instrument::instance()
    {
        static Instrument ins;
        return ins;
    }

    void Instrument::begin(const std::string& name, const std::string& filePath /*= "result.json"*/)
    {
        return EB_IMPL->begin(name, filePath);
    }

    void Instrument::end()
    {
        return EB_IMPL->end();
    }

    void Instrument::writeProfile(const ProfileResult& res)
    {
        return EB_IMPL->writeProfile(res);
    }

    InstrumentTimer::InstrumentTimer(const std::string& name)
    {
        EB_IMPL = createScoped<InstrumentTimerImpl>(name);
    }

    InstrumentTimer::InstrumentTimer(const char* name)
    {
        EB_IMPL = createScoped<InstrumentTimerImpl>(name);
    }

    InstrumentTimer::~InstrumentTimer()
    {
        EB_IMPL.release();
    }

    void InstrumentTimer::stop()
    {
        return EB_IMPL->stop();
    }

}