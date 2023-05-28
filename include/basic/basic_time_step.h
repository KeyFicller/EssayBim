#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"

namespace EB
{
    /*
     * @brief    this class is used to define delta time.
     */
    class EB_EXPORT TimeStep final
    {
        EB_IMPL_DECLARATION_ENABLE_COPY(TimeStep)
    public:
        /*
         * @brief   constructor of time step.
         * @param[in]   time     during time.
         */
        explicit TimeStep(float time = 0.f);

        /*
         * @brief   destructor of time step.
         */
        ~TimeStep();

    public:
        /*
         * @brief    get delta time from last call.
         * @return    delta time in seconds from last call.
         */
        static TimeStep deltaTime();

    public:
        /*
         * @brief   overload float casting.
         */
        operator float() const;

        /*
         * @brief   overload equal operation.
         */
        void operator = (float time);

        /*
         * @brief   cast time step into seconds.
         * @return   casted seconds.
         */
        float seconds() const;

        /*
         * @breif   cast time step into mileseconds.
         * @return   casted mileseconds.
         */
        float mileseconds() const;
    };
}