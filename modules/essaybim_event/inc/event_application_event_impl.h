#pragma once

#include "event_event_base_impl.h"

namespace EB
{
    class WindowResizedEventImpl : public EventImpl
    {
    public:
        WindowResizedEventImpl(Event* pFacade, unsigned int width, unsigned int height);
    public:
        unsigned int width() const;
        unsigned int height() const;
        std::string toString() const override;
    protected:
        unsigned int m_Width;
        unsigned int m_Height;
    };
}