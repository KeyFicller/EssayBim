#pragma once

#include "gui_base_widget.h"

namespace EB
{
    /**
     * @brief   this class defines tab widget item.
     */
    class EB_GUI_EXPORT TabWidgetItem : public BaseWidget
    {
    public:
        /**
         * @brief   constructor for tab widget item.
         * @param[in]     name     name of widget.
         * @param[in]     slot     main function on tab widget item activated.
         */
        TabWidgetItem(const std::string& name, const WidgetSlot& slot = nullptr);

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

    /**
     * @brief   this class defines tab widget.
     */
    class EB_GUI_EXPORT TabWidget : public BaseWidget
    {
    public:
        /**
         * @brief   constructor for tab widget item.
         * @param[in]     name     name of widget.
         * @param[in]     slot     main function on tab widget item activated.
         */
        TabWidget(const std::string& name, const WidgetSlot& slot = nullptr);

    public:
        /**
         * @brief   add tab item to tab widget.
         * @param[in]     item     shared pointer of item.
         */
        void addTabItem(const Shared<TabWidgetItem>& item);

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

    protected:
        /** < tab items > */
        std::vector<Shared<TabWidgetItem>> m_TabItems;
    };
}