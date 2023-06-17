#pragma once

#include "event_key_event.h"
#include "event_event_base_impl.h"

namespace EB
{
    class KeyEventImpl : public EventImpl
    {
    public:
        KeyEventImpl(Event* pFacade, int keyCode);
    public:
        int key() const;
        std::string toString() const override;
    protected:
        int m_KeyCode;
    };

    class KeyReleasedEventImpl : public KeyEventImpl
    {
    public:
        KeyReleasedEventImpl(Event* pFacade, int keyCode);
    public:
        std::string toString() const override;
    };

    class KeyPressedEventImpl : public KeyEventImpl
    {
    public:
        KeyPressedEventImpl(Event* pFacade, int keyCode, int repeatCount);
    public:
        int repeats() const;
        std::string toString() const override;
    protected:
        int m_Repeats;
    };

    class KeyTypedEventImpl : public KeyEventImpl
    {
    public:
        KeyTypedEventImpl(Event* pFacade, int keyCode);
    public:
        std::string toString() const override;
    };
}