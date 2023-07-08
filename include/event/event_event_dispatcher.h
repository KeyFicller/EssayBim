#pragma once

#include "event_event_base.h"
#include "event_export.h"

#include "basic_impl_template.h"


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
         * @brief  handle event if type matched.
         * @param[in]   f          function to execute
         * @param[in]   arg        event extension parameters.
         * @return  whether function is executed.
         */
        template <typename event_t, typename func, typename... Args>
        bool dispatch(const func& f, Args&&... args)
        {
            if (event().type() == event_t::staticType()) {
                if (f(static_cast<event_t&>(event()), std::forward<Args>(args)...)) {
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