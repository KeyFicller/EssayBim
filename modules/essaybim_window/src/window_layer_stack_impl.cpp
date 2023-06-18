#include "window_layer_stack_impl.h"

namespace EB
{

    LayerStackImpl::LayerStackImpl()
    {

    }

    LayerStackImpl::~LayerStackImpl()
    {
        for (auto& layer : m_Layers) {
            layer->onAttach();
        }
        m_Layers.clear();
    }

    void LayerStackImpl::pushLayer(const Shared<Layer>& layer)
    {
        m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
        m_LayerInsertIndex++;
        layer->onAttach();
    }

    void LayerStackImpl::pushOverLayer(const Shared<Layer>& layer)
    {
        m_Layers.emplace_back(layer);
        layer->onAttach();
    }

    void LayerStackImpl::popLayer(const Shared<Layer>& layer)
    {
        auto iter = std::find(m_Layers.begin(), m_Layers.end(), layer);
        if (iter != m_Layers.end()) {
            layer->onDetach();
            m_Layers.erase(iter);
            if (std::distance(m_Layers.begin(), iter) < m_LayerInsertIndex) {
                m_LayerInsertIndex--;
            }
        }
    }

    void LayerStackImpl::popOverLayer()
    {
        if (!m_Layers.empty()) {
            m_Layers.back()->onDetach();
            m_Layers.pop_back();
        }
    }

    const std::vector<Shared<Layer>>& LayerStackImpl::layers() const
    {
        return m_Layers;
    }

}