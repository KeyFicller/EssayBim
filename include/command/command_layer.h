#pragma once

#include "command_base.h"
#include "command_export.h"

#include "window_layer.h"

namespace EB
{
    /**
     * @biref  this class defines command layer, embed a command execution
     * environment to application run loop.
     */
    class EB_COMMAND_EXPORT CommandLayer : public Layer
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(CommandLayer)
    public:
        /**
         * @brief   constructor for layer,
         * @param[in]   pBase    point for command been executed.
         */
        CommandLayer(CommandBase* pBase);

        /**
         * @brief   destructor for layer.
         */
        virtual ~CommandLayer();

    public:
        /**
         * @brief  handle layer attach.
         */
        void onAttach() override;

        /**
         * @brief  handle layer detach.
         */
        void onDetach() override;

        /**
         * @brief  handle layer update.
         * @param[in]  ts   real time spent.
         */
        void onUpdate(const TimeStep& ts) override;

        /**
         * @brief   handle ui render.
         */
        void onGuiRender() override;

        /**
         * @brief   handle event.
         * @param[in]   e   event.
         */
        void onEvent(Event& e) override;

        /**
         * @brief   if command has finished.
         * @return   whether this command finished.
         */
        bool hasCommandFinished();

    };
}