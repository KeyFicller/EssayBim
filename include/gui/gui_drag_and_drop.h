#pragma once

#include "gui_base_widget.h"

#include "basic_filer.h"

namespace EB
{
    /**
     * @brief  this class defines drag and drop base.
     */
    class EB_GUI_EXPORT DragAndDropBase : public BaseWidget
    {
    public:
        /** < encode function with filer > */
        using EncodeFunc = std::function<void(Filer* filer)>;

        /** < decode function with filer > */
        using DecodeFunc = std::function<void(const Filer* filer)>;

    protected:
        /**
         * @brief  constructor for drag and drop base.
         * @param[in]    label      label for drag and drop.
         */
        DragAndDropBase(const std::string& label);

    protected:
        /** < label for drag and drop > */
        std::string m_Label;
    };

    /**
     * @brief   this class defines drag source.
     */
    class EB_GUI_EXPORT DragSource : public DragAndDropBase
    {
    public:
        /**
         * @brief  constructor for drag source.
         * @param[in]    label    label for drag and drop.
         * @param[in]    encode   encode function for data export.
         */
        DragSource(const std::string& label, const EncodeFunc& encode);

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
        /** < encode function for data export > */
        EncodeFunc m_Encode = nullptr;
    };

    /**
     * @brief  this class defines drop target.
     */
    class EB_GUI_EXPORT DropTarget : public DragAndDropBase
    {
    public:
        /**
         * @brief   constructor for drop target.
         * @param[in]    label    label for drag and drop.
         * @param[in]    decode   decode function for data import.
         */
        DropTarget(const std::string& label, const DecodeFunc& decode);

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
        /** < decode function for data import > */
        DecodeFunc m_Decode = nullptr;
    };
}