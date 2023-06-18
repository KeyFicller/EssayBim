#pragma once

#include "window_layer.h"

namespace EB
{
    class LayerImpl
    {
    public:
        LayerImpl(const std::string& name);
    public:
        const std::string& name() const;
    protected:
        std::string m_Name;
    };
}