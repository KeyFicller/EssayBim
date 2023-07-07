#pragma once

#include "command_layer.h"

namespace EB
{
    class CommandLayerImpl
    {
    public:
        CommandLayerImpl(CommandBase* pCommand);
        virtual ~CommandLayerImpl();
    public:
        void onAttach();
        void onDetach();
        void onUpdate(const TimeStep& ts);
        void onGuiRender();
        void onEvent(Event& e);
        bool hasCommandFinished();

    protected:
        CommandBase* m_pCommand = nullptr;
    };
}