#pragma once

#include "window_layer_stack.h"

namespace EB
{
    class LayerStackImpl final
    {
    public:
        LayerStackImpl();
        ~LayerStackImpl();

    public:
        void pushLayer(const Shared<Layer>& layer);
        void pushOverLayer(const Shared<Layer>& layer);
        void popLayer(const Shared<Layer>& layer);
        void popOverLayer();
        const std::vector<Shared<Layer>>& layers() const;

    private:
        std::vector<Shared<Layer>> m_Layers;
        unsigned int m_LayerInsertIndex = 0;
    };
}