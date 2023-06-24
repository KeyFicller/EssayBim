#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"

#include <string>
#include <functional>

namespace EB
{
    class BaseWidgetImpl;

    /**
     * @brief   this class define base widget.
     */
    class EB_EXPORT BaseWidget
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(BaseWidget)
    public:
        using WidgetSlot = std::function<void(void)>;
    public:
        /**
         * @brief   constructor for base widget.
         * @param[in]  name   identifier and display name of widget.
         */
        BaseWidget(const std::string& name = std::string());

        /**
         * @brief   constructor for base widget.
         * @param[in]  impl  implement of derived class.
         */
        BaseWidget(BaseWidgetImpl& impl);

        /**
         * @brief   destructor for base widget.
         */
        virtual ~BaseWidget();

    public:
        /**
         * @brief   handle gui render.
         */
        void onGuiRender();

        /**
         * @brief   set visibility of widget name.
         * @param[in]  visible   whether name be visible.
         */
        void setNameVisibility(bool visible = true);

        /**
         * @brief   set enabled of widget.
         * @param[in]  enable    whether widget be enabled.
         */
        void setEnabled(bool enable = true);

        /**
         * @brief   set tool tip for widget.
         * @param[in]   slot     slot for tool tip render.
         */
        void setToolTip(const WidgetSlot& slot);

    protected:
        /**
         * @brief   get widget name visibility.
         * @return  whether widget name is visible.
         */
        bool isNameVisible() const;

        /**
         * @brief   set main function for widget.
         * @param[in]    slot   main logic function.
         */
        void setSlot(const WidgetSlot& slot);

        /**
         * @brief   get widget name.
         * @return   name of widget.
         */
        const std::string name() const;
        
    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        virtual bool subOnImguiRender() = 0;

        /**
         * @brief   push custom style for widget.
         */
        virtual void pushStyle();

        /**
         * @brief   pop custom style for widget.
         */
        virtual void popStyle();

        /**
         * @brief   restore stack data after rendering.
         */
        virtual void postAction();
    };
}

#define EB_WIDGET_SLOT(_func)       [&](){_func}

#define EB_WIDGET_IMMEDIATE(_widget_class, ...)  do { \
    _widget_class(__VA_ARGS__).onGuiRender();         \
} while (0)