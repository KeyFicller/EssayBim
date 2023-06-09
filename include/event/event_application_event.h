#pragma once

#include "event_event_base.h"

namespace EB
{
    /**
     * @brief   this class defines window resized event
     */
    class EB_EVENT_EXPORT WindowResizedEvent : public Event
    {
        EB_EVENT_DECLARE_TYPE(kWindowResized)
    public:
        /**
         * @brief   constructor for window resize event.
         * @param[in]   width       width of resized window.
         * @param[in]   height      height of resized window.
         */
        WindowResizedEvent(unsigned int width, unsigned int height);
    public:
        /**
         * @brief   get width of resized window.
         * @return  width of resized window.
         */
        unsigned int width() const;

        /**
         * @brief   get height of resized window.
         * @return  height of resized window.
         */
        unsigned int height() const;
    };

    /**
     * @brief  this class defines window closed event.
     */
    class EB_EVENT_EXPORT WindowClosedEvent : public Event
    {
        EB_EVENT_DECLARE_TYPE(kWindowClosed)
    public:
        /**
         * @brief   constructor for window closed event.
         */
        WindowClosedEvent();
    };
}