#pragma once

#include "event_event_base.h"

namespace EB
{
    class MouseButtonEventImpl;

    /**
     * @brief  this class defines mouse button event.
     */
    class EB_EXPORT MouseButtonEvent : public Event
    {
    public:
        /**
         * @brief   constructor for mouse button event.
         * @param[in]  mouseButton   mouse button identifier.
         */
        MouseButtonEvent(int mouseButton);

        /**
         * @brief   constructor for mouse button event.
         * @param[in]  impl       implement of derive classes.
         */
        MouseButtonEvent(MouseButtonEventImpl& impl);

    public:
        /**
         * @brief  get mouse button.
         * @return mouse button.
         */
        int button() const;
    };

    /**
     * @brief   this class defines mouse button pressed event.
     */
    class EB_EXPORT MouseButtonPressedEvent : public MouseButtonEvent
    {
        EB_EVENT_DECLARE_TYPE(kMouseButtonPressed)
    public:
        /**
         * @brief  constructor for mouse button pressed event.
         * @param[in]  mouseButton   mouse button identifier. 
         */
        MouseButtonPressedEvent(int mouseButton, int repeatCount);

    public:
        /**
         * @brief  get repeat count of key.
         * @return repeat count of key.
         */
        int repeats() const;
    };

    /**
     * @brief   this class defines mouse button released event.
     */
    class EB_EXPORT MouseButtonReleasedEvent : public MouseButtonEvent
    {
        EB_EVENT_DECLARE_TYPE(kMouseButtonReleased)
    public:
        /**
         * @brief  constructor for mouse button released event.
         * @param[in]  mouseButton   mouse button identifier.
         */
        MouseButtonReleasedEvent(int mouseButton);
    };
}