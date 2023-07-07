#include "command_layer.h"

#include "command_layer_impl.h"

namespace EB
{

    CommandLayer::CommandLayer(CommandBase* pBase)
    {
        EB_IMPL() = createScoped<CommandLayerImpl>(pBase);
    }

    CommandLayer::~CommandLayer()
    {
        EB_IMPL().reset();
    }

    void CommandLayer::onAttach()
    {
        EB_IMPL()->onAttach();
    }

    void CommandLayer::onDetach()
    {
        EB_IMPL()->onDetach();
    }

    void CommandLayer::onUpdate(const TimeStep& ts)
    {
        EB_IMPL()->onUpdate(ts);
    }

    void CommandLayer::onGuiRender()
    {
        EB_IMPL()->onGuiRender();
    }

    void CommandLayer::onEvent(Event& e)
    {
        EB_IMPL()->onEvent(e);
    }

}