#pragma once

#include "gui_base_widget.h"

namespace EB
{
    /**
     * @brief  this class defines modal widget.
     */
    class EB_EXPORT ModalWidget : public BaseWidget
    {
    public:
        /**
         * @brief   constructor for modal widget.
         * @param[in]    name       name of widget.
         * @param[in]    slot       main function on modal widget active.
         */
        ModalWidget(const std::string& name, const WidgetSlot& slot = nullptr);

    public:
        /**
         * @brief   close current active modal widget.
         */
        static void closeCurrentModalWidget();

    public:
        /**
         * @brief   get signal to active modal widget.
         * <p>
         * outside will call the slot and modal widget will be active.
         * @return    modal widget active signal.
         */
        WidgetSlot activeSignal();

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

        /**
         * @brief   restore stack data after rendering.
         */
        void postAction() override;
    };
}