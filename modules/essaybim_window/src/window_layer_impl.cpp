#include "window_layer_impl.h"

namespace EB
{
    LayerImpl::LayerImpl(const std::string& name)
        : m_Name(name)
    {

    }

    const std::string& LayerImpl::name() const
    {
        return m_Name;
    }

}