#include "event_event_base_impl.h"

#pragma warning(disable: 26812)

namespace EB
{

    EventImpl::EventImpl(Event* pFacade)
        : m_pFacade(pFacade)
    {

    }

    std::string EventImpl::toString() const
    {
        return "";
    }

    bool EventImpl::isInCategory(eEventCategory category)
    {
        return (m_pFacade->type() & category) == category;
    }

    bool EventImpl::isHandled() const
    {
        return m_IsHandled;
    }

    void EventImpl::setHandled(bool handled /*= true*/)
    {
        m_IsHandled = handled;
    }

}