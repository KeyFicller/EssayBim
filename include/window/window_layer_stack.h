#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"

#include "window_layer.h"

#include <vector>

namespace EB
{
    /**
     * @brief   this class defines layer stack.
     */
    class EB_EXPORT LayerStack final
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(LayerStack)
    public:
        /**
         * @brief   constructor for layer stack.
         */
        LayerStack();

        /**
         * @brief   destructor for layer stack.
         */
        ~LayerStack();

    public:
        /**
         * @brief   push a layer at current index.
         * @param[in]   layer    pushed layer.
         */
        void pushLayer(const Shared<Layer>& layer);

        /**
         * @brief   push a over layer to stack.
         * @param[in]   layer    pushed layer.
         */
        void pushOverLayer(const Shared<Layer>& layer);

        /**
         * @brief   pop specified layer.
         * @param[in]   layer    poped layer.
         */
        void popLayer(const Shared<Layer>& layer);

        /**
         * @brief   pop the most up layer from stack. 
         */
        void popOverLayer();

        /**
         * @brief   get layers.
         * @return   layers.
         */
        const std::vector<Shared<Layer>>& layers() const;
    };
}