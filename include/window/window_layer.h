#pragma once

#include "window_export.h"

#include "basic_impl_template.h"
#include "basic_time_step.h"
#include "event_event_base.h"

#include <string>

namespace EB
{
    /**
     * @brief  this class is used to define renderer layer.
     */
    class EB_WINDOW_EXPORT Layer
    {
    public:
        /**
         * @brief   constructor for layer,
         */
        Layer();

        /**
         * @brief   destructor for layer.
         */
        virtual ~Layer();

    public:
        /**
         * @brief  handle layer attach.
         */
        virtual void onAttach() = 0;

        /**
         * @brief  handle layer detach.
         */
        virtual void onDetach() = 0;

        /**
         * @brief  handle layer update.
         * @param[in]  ts   real time spent.
         */
        virtual void onUpdate(const TimeStep& ts) = 0;

        /**
         * @brief   handle ui render.
         */
        virtual void onGuiRender() = 0;

        /**
         * @brief   handle event.
         * @param[in]   e   event.
         */
        virtual void onEvent(Event& e) = 0;

    };
}