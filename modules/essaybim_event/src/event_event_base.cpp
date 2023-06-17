#include "event_event_base.h"

#include "event_event_base_impl.h"

namespace EB
{

    Event::Event()
    {
        EB_IMPL = createScoped<EventImpl>(this);
    }

    Event::Event(EventImpl& impl)
    {
        EB_IMPL = std::unique_ptr<EventImpl>(&impl);
    }

    Event::~Event()
    {
        EB_IMPL.reset();
    }

    std::string Event::toString() const
    {
        return EB_IMPL->toString();
    }

    bool Event::isInCategory(eEventCategory category)
    {
        return EB_IMPL->isInCategory(category);
    }

    bool Event::isHandled() const
    {
        return EB_IMPL->isHandled();
    }

    void Event::setHandled(bool handled /*= true*/)
    {
        EB_IMPL->setHandled(handled);
    }

}