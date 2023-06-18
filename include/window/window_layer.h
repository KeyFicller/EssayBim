#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"
#include "basic_time_step.h"

#include "event_event_base.h"

#include <string>

namespace EB
{
    /**
     * @brief  this class is used to define renderer layer.
     */
    class EB_EXPORT Layer
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(Layer)
    public:
        /**
         * @brief   constructor for layer,
         * @param[in]   name    name of layer.
         */
        Layer(const std::string& name);

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

    public:
        /**
         * @brief  get layer name.
         * @return layer name.
         */
        const std::string& name() const;
    };
}