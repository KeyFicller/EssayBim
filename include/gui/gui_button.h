#pragma once

#include "gui_base_widget.h"
#include "basic_vector.h"

namespace EB
{
    /**
     * @brief  this class defines button widget.
     */
    class EB_EXPORT Button : public BaseWidget
    {
    public:
        /**
         * @brief    constructor for button widget.
         * @param[in]   name    name of widget.
         * @param[in]   slot    main function on button triggered.
         */
        Button(const std::string& name, const WidgetSlot& slot = nullptr);

        /**
         * @brief    constructor for button widget.
         * @param[in]   name    name of widget.
         * @param[in]   size    size of widget.
         * @param[in]   slot    main function on button triggered.
         */
        Button(const std::string& name, const Vec2& size, const WidgetSlot& slot = nullptr);
    public:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender();

    protected:
        /** < button size > */
        Vec2 m_Size = Vec2(0.f, 0.f);
    };
}