#pragma once

#include "gui_base_widget.h"

namespace EB
{
    /**
     * @brief  this class defines menu item of menu bar.
     */
    class EB_GUI_EXPORT MenuBarMenuItem : public BaseWidget
    {
    public:
        /**
         * @brief   constructor for menu item of menu bar.
         * @param[in]   name         name of widget.
         * @param[in]   shortCut     short cut of this action.
         * @param[in]    slot   main logic function.
         */
        MenuBarMenuItem(const std::string& name, const std::string& shortCut = std::string(), const WidgetSlot& slot = nullptr);

    public:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

    protected:
        /** < short cut hint string > */
        std::string m_ShortCut;
    };

    /**
     * @brief  this class defines menu of menu bar.
     */
    class EB_GUI_EXPORT MenuBarMenu : public BaseWidget
    {
    public:
        /**
         * @brief   constructor for menu of menu bar.
         * @param[in]   name         name of widget.
         */
        MenuBarMenu(const std::string& name);

    public:
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
         * @brief   add a menu item to this menu.
         * @param[in]   item     menu item of menu.
         */
        void addMenuItem(const Shared<MenuBarMenuItem>& item);

    protected:
        /** < contanier of menu items > */
        std::vector< Shared<MenuBarMenuItem>> m_MenuItems;
    };

    /**
     * @brief   this class defines menu bar.
     */
    class EB_GUI_EXPORT MenuBar : public BaseWidget
    {
    public:
        /**
         * @brief   constructor for menu bar.
         */
        MenuBar();

    public:
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
         * @brief   add a menu to menu bar.
         * @param[in]   menu      menu of menu bar.
         */
        void addMenu(const Shared<MenuBarMenu>& menu);

    protected:
        /** < container of menus > */
        std::vector<Shared<MenuBarMenu>> m_Menus;
    };
}