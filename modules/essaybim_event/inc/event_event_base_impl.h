#pragma once

#include "event_event_base.h"

namespace EB
{
    class EventImpl
    {
    public:
        EventImpl(Event* pFacade);
        ~EventImpl() = default;

    public:
        virtual std::string toString() const;
        bool isInCategory(eEventCategory category);
        bool isHandled() const;
        void setHandled(bool handled = true);

    protected:
        bool m_IsHandled = false;
        Event* m_pFacade = nullptr;
    };
}