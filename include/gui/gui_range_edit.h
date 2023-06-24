#pragma once

#include "gui_base_widget.h"

namespace EB
{
    /**
     * @brief   this class defines range edit for float data.
     */
    class EB_EXPORT RangeEditF : public BaseWidget
    {
    public:
        /**
         * @brief   constructor for range edit.
         * @param[in]    name      name of widget.
         * @param[in]    min       range minimum.
         * @param[in]    max       range maximum.
         */
        RangeEditF(const std::string& name, float& min, float& max, const WidgetSlot& slot = nullptr);

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

    protected:
        /** < range minimim > */
        float& m_Min;

        /** < range minimim > */
        float& m_Max;
    };

    /**
     * @brief   this class defines range edit for int data.
     */
    class EB_EXPORT RangeEditI : public BaseWidget
    {
    public:
        /**
         * @brief   constructor for range edit.
         * @param[in]    name      name of widget.
         * @param[in]    min       range minimum.
         * @param[in]    max       range maximum.
         */
        RangeEditI(const std::string& name, int& min, int& max, const WidgetSlot& slot = nullptr);

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

    protected:
        /** < range minimim > */
        int& m_Min;

        /** < range minimim > */
        int& m_Max;
    };
}