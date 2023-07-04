#pragma once

#include "event_event_base.h"

namespace EB
{
    /**
     * @brief   this class defines mouse move event.
     */
    class EB_EVENT_EXPORT MouseMovedEvent : public Event
    {
        EB_EVENT_DECLARE_TYPE(kMouseMoved)
    public:
        /**
         * @brief  constructor for mouse move event.
         * @param[in]   x    x coordinate of mouse.
         * @param[in]   y    y coordinate of mouse.
         */
        MouseMovedEvent(float x, float y);
    public:
        /**
         * @brief  get x coordinate of mouse.
         * @return  x coordinate of mouse.
         */
        float x() const;

        /**
         * @brief  get y coordinate of mouse.
         * @return  y coordinate of mouse.
         */
        float y() const;
    };

    class EB_EVENT_EXPORT MouseScrolledEvent : public Event
    {
        EB_EVENT_DECLARE_TYPE(kMouseScrolled)
    public:
        /**
         * @brief  constructor for mouse scrolled event.
         * @param[in]   x    x scroll of mouse.
         * @param[in]   y    y scroll of mouse.
         */
        MouseScrolledEvent(float x, float y);
    public:
        /**
         * @brief  get x scroll of mouse.
         * @return  x scroll of mouse.
         */
        float x() const;

        /**
         * @brief  get y scroll of mouse.
         * @return  y scroll of mouse.
         */
        float y() const;
    };
}