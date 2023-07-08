#pragma once

#include "editor_export.h"

#include "event_event_base.h"
#include "basic_handle.h"
#include "geometry_line_3d.h"

namespace EB
{
    /**
     * @brief  this class defines Editor Base
     */
    class EB_EDITOR_EXPORT EditorBase
    {
    public:
        /**
         * @brief  this enum defines editor status.
         */
        enum class EditorStatus
        {
            /** < editor is on interacting > */
            kInterating,

            /** < editor is confirmed and about to exit > */
            kConfirmed,

            /** < editor is about to cancel > */
            kCanceled
        };

        /**
         * @brief  this class define extra interact information for editor.
         */
        struct EventExtension
        {
            /** < ray line from current camera > */
            GeLine3d MouseRayLine;

            /** < entity handle from current selection > */
            Handle EntityHandle;
        };

    public:
        /**
         * @brief   constructor for editor base.
         */
        EditorBase();

        /**
         * @brief   destructor for editor base.
         */
        virtual ~EditorBase();

    public:
        /**
         * @brief  get editor status
         */
        virtual EditorStatus status() = 0;

        /**
         * @brief    init editor.
         */
        virtual void init() = 0;

        /**
         * @brief    handle input event for input.
         */
        virtual void handleInput(Event& e, const EventExtension& extension) = 0;

        /**
         * @brief    editor update.
         */
        virtual void update() = 0;

        /**
         * @brief    editor update display.
         */
        virtual void updateDisplay() = 0;

        /**
         * @brief    editor confirmed.
         */
        virtual void confirm() = 0;

        /**
         * @brief    editor canceled.
         */
        virtual void cancel() = 0;
    };
}