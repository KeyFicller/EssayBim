#include "event_application_event_impl.h"

#include <sstream>

namespace EB
{

    WindowResizedEventImpl::WindowResizedEventImpl(Event* pFacade, unsigned int width, unsigned int height)
        : EventImpl(pFacade), m_Width(width), m_Height(height)
    {

    }

    unsigned int WindowResizedEventImpl::width() const
    {
        return m_Width;
    }

    unsigned int WindowResizedEventImpl::height() const
    {
        return m_Height;
    }

    std::string WindowResizedEventImpl::toString() const
    {
        std::stringstream ss;
        ss << m_pFacade->name() << ": " << m_Width << ", " << m_Height;
        return ss.str();
    }

}