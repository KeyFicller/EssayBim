#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"

#include <string>

namespace EB
{
    /*
     * @brief   this struct define profile result.
     */
    struct ProfileResult
    {
        /* < profile object name for identifier > */
        std::string Name;

        /* < profile start time > */
        long long StartTime;

        /* < profile end time > */
        long long EndTime;

        /* < profile thread id > */
        unsigned int ThreadId;
    };

    /*
     * @brief   this class is used for instrument profile.
     */
    class EB_EXPORT Instrument final
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(Instrument)
    protected:
        /*
         * @brief  constructor of Instrument.
         */
        Instrument();

    public:
        /*
         * @brief   get global instrument instance.
         */
        static Instrument& instance();

    public:
        /*
         * @brief  begin instrument.
         * <p>
         * drag exported file to 'edge::tracing' for illusion.
         * @param[in]   name      this profile name.
         * @param[in]   filePath  export profile file path.
         */
        void begin(const std::string& name, const std::string& filePath = "result.json");

        /*
         * @brief  end instrument.
         */
        void end();

        /*
         * @brief  write profile result to stream cache.
         * @param[in]   res      profile result.
         */
        void writeProfile(const ProfileResult& res);
    };

    /*
     * @brief      this class is used for profiling timer.
     */
    class EB_EXPORT InstrumentTimer final
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(InstrumentTimer)
    public:
        /*
         * @brief   constructor for timer.
         * @param[in]    name  identifier for this timer.
         */
        explicit InstrumentTimer(const std::string& name);

        /*
         * @brief   constructor for timer.
         * @param[in]    name  identifier for this timer.
         */
        explicit InstrumentTimer(const char* name);

        /*
         * @brief   destructor for timer.
         */
        ~InstrumentTimer();

    public:
        /*
         * @brief   stop timer, and write profile result to instrument.
         */
        void stop();
    };
}


#define EB_PROFILE_BEGIN(_name, _filePath)  ::EB::Instrument::instance().begin(_name, _filePath)
#define EB_PROFILE_END()                    ::EB::Instrument::instance().end()
#define EB_PROFILE_SCOPED(_name)            ::EB::InstrumentTimer timer##__LINE__(_name)
#define EB_PROFILE_FUNCTION()               EB_PROFILE_SCOPED(__FUNCSIG__)