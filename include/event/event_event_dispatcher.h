#pragma once

#include "event_export.h"
#include "basic_impl_template.h"

#include "event_event_base.h"

namespace EB
{
    /**
     * @brief  this class define event dispatcher.
     */
    class EB_EVENT_EXPORT EventDispatcher
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(EventDispatcher)
    public:
        /**
         * @brief  constructor for event dispatcher.
         * @param[in]   event      event to handle.
         */
        EventDispatcher(Event& event);

        /**
         * @brief   destructor for event dispatcher.
         */
        ~EventDispatcher();

    public:
        /**
         * @brief  handle event if type matched.
         * @param[in]   f          function to execute
         * @return  whether function is executed.
         */
        template <typename event_t, typename func>
        bool dispatch(const func& f)
        {
            if (event().type() == event_t::staticType()) {
                if (f(static_cast<event_t&>(event()))) {
                    event().setHandled(true);
                }
                return true;
            }
            return false;
        }

        /**
         * @brief  get event.
         * @return  reference to event.
         */
        Event& event();
    };
}