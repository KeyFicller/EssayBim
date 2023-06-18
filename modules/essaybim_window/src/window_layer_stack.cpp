#include "window_layer_stack.h"

#include "window_layer_stack_impl.h"

namespace EB
{

    LayerStack::LayerStack()
    {
        EB_IMPL() = createScoped<LayerStackImpl>();
    }

    LayerStack::~LayerStack()
    {
        EB_IMPL().reset();
    }

    void LayerStack::pushLayer(const Shared<Layer>& layer)
    {
        EB_IMPL()->pushLayer(layer);
    }

    void LayerStack::pushOverLayer(const Shared<Layer>& layer)
    {
        EB_IMPL()->pushOverLayer(layer);
    }

    void LayerStack::popLayer(const Shared<Layer>& layer)
    {
        EB_IMPL()->popLayer(layer);
    }

    void LayerStack::popOverLayer()
    {
        EB_IMPL()->popOverLayer();
    }

    const std::vector<Shared<Layer>>& LayerStack::layers() const
    {
        return EB_IMPL()->layers();
    }

}