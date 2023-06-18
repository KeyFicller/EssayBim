#include "window_layer.h"

#include "window_layer_impl.h"

namespace EB
{

    Layer::Layer(const std::string& name)
    {
        EB_IMPL() = createScoped<LayerImpl>(name);
    }

    Layer::~Layer()
    {
        EB_IMPL().reset();
    }

    const std::string& Layer::name() const
    {
        return EB_IMPL()->name();
    }

}