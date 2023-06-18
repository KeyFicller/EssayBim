#pragma once

#include "event_event_base.h"

namespace EB
{
    class KeyEventImpl;

    /**
     * @brief  this class define key event.
     */
    class EB_EXPORT KeyEvent : public Event
    {
    public:
        /**
         * @brief  constructor for key event.
         * @param[in]   keyCode  identifier of key.
         */
        KeyEvent(int keyCode);

        /**
         * @brief  constructor for key event.
         * @param[in]   impl     implement class for derived class.
         */
        KeyEvent(KeyEventImpl& impl);

    public:
        /**
         * @brief  get key code of key event.
         * @return keyCode of key event.
         */
        int key() const;
    };

    /**
     * @brief   this class define key released event
     */
    class EB_EXPORT KeyReleasedEvent : public KeyEvent
    {
        EB_EVENT_DECLARE_TYPE(kKeyReleased)
    public:
        /**
         * @brief   constructor for key released event.
         * @param[in]  keyCode   identifier of key.
         */
        KeyReleasedEvent(int keyCode);
    };

    /**
     * @brief   this class defines key pressed event.
     */
    class EB_EXPORT KeyPressedEvent : public KeyEvent
    {
        EB_EVENT_DECLARE_TYPE(kKeyPressed)
    public:
        /**
         * @brief   constructor for key pressed event.
         * @param[in]   keyCode   identifier of key.
         * @param[in]   repeatCount   repeat count of key.
         */
        KeyPressedEvent(int keyCode, int repeatCount);
    public:
        /**
         * @brief  get repeat count of key.
         * @return repeat count of key.
         */
        int repeats() const;
    };

    /**
     * @brief   this class defines key typed event.
     */
    class EB_EXPORT KeyTypedEvent : public KeyEvent
    {
        EB_EVENT_DECLARE_TYPE(kKeyTyped)
    public:
        /**
         * @brief  constructor for key typed event.
         * @param[in]   keyCode   identifier of key.
         */
        KeyTypedEvent(int keyCode);
    };
}