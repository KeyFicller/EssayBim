#pragma once

#include "gui_base_widget.h"

namespace EB
{
    /**
     * @brief   this class defines pop-up menu item.
     */
    class EB_GUI_EXPORT PopupMenuItem : public BaseWidget
    {
    public:
        /**
         * @brief  constructor for pop-up menu item.
         * @param[in]   slot     main function on pop-up item selected.
         */
        PopupMenuItem(const WidgetSlot& slot = nullptr);

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;
    };


    class EB_GUI_EXPORT PopupMenu : public BaseWidget
    {
    public:
        /**
         * @brief   constructor for pop-up menu.
         * @param[in]    name         name of widget.
         * @param[in]    menuItems    items of pop up menu.
         */
        PopupMenu(const std::string& name, const std::vector<PopupMenuItem>& menuItems = {});

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

    public:
        /**
         * @brief   add a menu item to pop up menu.
         * @param[in]   item     menu item.
         */
        void addMenuItem(const PopupMenuItem& item);

        /**
         * @brief   get signal to active pop-up menu.
         * <p>
         * outside will call the slot and pop-up menu will be active.
         * @return    pop-up menu active signal.
         */
        WidgetSlot activateSignal();

    private:
        /** < container of pop-up menu items > */
        std::vector<PopupMenuItem> m_MenuItems;
    };
}