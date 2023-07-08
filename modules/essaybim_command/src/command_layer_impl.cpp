#include "command_layer_impl.h"

namespace EB
{

    CommandLayerImpl::CommandLayerImpl(CommandBase* pCommand)
        : m_pCommand(pCommand)
    {

    }

    CommandLayerImpl::~CommandLayerImpl()
    {

    }

    void CommandLayerImpl::onAttach()
    {
        m_pCommand->beginInvoke();
    }

    void CommandLayerImpl::onDetach()
    {
        m_pCommand->endInvoke();
    }

    void CommandLayerImpl::onUpdate(const TimeStep& ts)
    {
        m_pCommand->editor().update();
    }

    void CommandLayerImpl::onGuiRender()
    {
        m_pCommand->editor().updateDisplay();
    }

    void CommandLayerImpl::onEvent(Event& e)
    {
        m_pCommand->editor().handleInput(e);
    }

    bool CommandLayerImpl::hasCommandFinished()
    {
        return m_pCommand->editor().status() != EditorBase::EditorStatus::kInterating;
    }

}