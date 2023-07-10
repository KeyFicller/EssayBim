#include "essaybim_redo_cmd.h"

#include "editor_base.h"
#include "command_undo_manager.h"

namespace EB
{
    class RedoEditor : public EditorBase
    {
    public:
        RedoEditor() = default;
        ~RedoEditor() override = default;

    public:
        EditorStatus status() override { return EditorBase::EditorStatus::kConfirmed; }
        void init() override {}
        void handleInput(Event& e, const EventExtension& extension) override {}
        void update() override {}
        void updateDisplay() override {}
        void confirm() override {}
        void cancel() override {}
    };


    RedoCmd::RedoCmd()
    {
        m_pEditor = new RedoEditor();
    }

    RedoCmd::~RedoCmd()
    {
        EB_SAFE_DELETE(m_pEditor);
    }

    void RedoCmd::beginInvoke()
    {
        CommandBase::beginInvoke();
        UndoManager::instance().redo();
    }

    EditorBase& RedoCmd::editor()
    {
        return *m_pEditor;
    }

    CommandAttribute RedoCmd::attribute()
    {
        return { "Redo", CommandAttribute::CommandType::kRedo };
    }

    bool RedoCmd::isRunnable() const
    {
        return UndoManager::instance().commandsInRedoStack().size();
    }

}