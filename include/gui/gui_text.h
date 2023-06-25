#pragma once

#include "gui_base_widget.h"

#include "basic_vector.h"

#include <string>

namespace EB
{
    class TextImpl;

    /**
     * @brief  this class defines text class.
     */
    class EB_EXPORT Text : public BaseWidget
    {
    public:
        /**
         * @biref  constructor for text.
         * @param[in]  name    name and display string of widget.
         */
        Text(const std::string& name);

        /**
         * @brief  constructor for text.
         * @param[in]  fmt     format string.
         * @param[in]  ...     format args.
         */
        Text(const char* fmt, ...);
        /**
         * @brief   constructor for base widget.
         * @param[in]  impl  implement of derived class.
         */
        Text(TextImpl& impl);

    public:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;
    };

    /**
     * @brief  this class defines colored text.
     */
    class EB_EXPORT ColoredText : public Text
    {
    public:
        /**
         * @brief   constructor for colored text.
         * @param[in]    color     color of text.
         * @param[in]    name      name and display string of widget.
         */
        ColoredText(const Vec4f& color, const std::string& name);

        /**
         * @brief  constructor for colored text.
         * @param[in]    color     color of text.
         * @param[in]  fmt     format string.
         * @param[in]  ...     format args.
         */
        ColoredText(const Vec4f& color, const char* fmt, ...);

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

    protected:
        /** < color of text > */
        Vec4f m_Color;
    };

    /**
     * @brief  this class defines gray text.
     */
    class EB_EXPORT GrayText : public Text
    {
    public:
        /**
         * @brief   constructor for gray text.
         * @param[in]    name      name and display string of widget.
         */
        GrayText(const std::string& name);

        /**
         * @brief  constructor for gray text.
         * @param[in]  fmt     format string.
         * @param[in]  ...     format args.
         */
        GrayText(const char* fmt, ...);

    protected:
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;
    };
}