#pragma once

#include "event_mouse_event.h"
#include "event_event_base_impl.h"

namespace EB
{
    class MouseMovedEventImpl : public EventImpl
    {
    public:
        MouseMovedEventImpl(Event* pFacade, float x, float y);
    public:
        std::string toString() const override;
        float x() const;
        float y() const;
    protected:
        float m_X;
        float m_Y;
    };

    class MouseScrolledEventImpl : public EventImpl
    {
    public:
        MouseScrolledEventImpl(Event* pFacade, float x, float y);
    public:
        std::string toString() const override;
        float x() const;
        float y() const;
    protected:
        float m_X;
        float m_Y;
    };
}