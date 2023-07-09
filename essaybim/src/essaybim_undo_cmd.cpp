#include "essaybim_undo_cmd.h"

#include "editor_base.h"
#include "command_undo_manager.h"

namespace EB
{
    class UndoEditor : public EditorBase
    {
    public:
        UndoEditor() = default;
        ~UndoEditor() override = default;

    public:
        EditorStatus status() override { return EditorBase::EditorStatus::kConfirmed; }
        void init() override {}
        void handleInput(Event& e, const EventExtension& extension) override {}
        void update() override {}
        void updateDisplay() override {}
        void confirm() override {}
        void cancel() override {}
    };


    UndoCmd::UndoCmd()
    {
        m_pEditor = new UndoEditor();
    }

    UndoCmd::~UndoCmd()
    {
        EB_SAFE_DELETE(m_pEditor);
    }

    void UndoCmd::beginInvoke()
    {
        CommandBase::beginInvoke();
        UndoManager::instance().undo();
    }

    EditorBase& UndoCmd::editor()
    {
        return *m_pEditor;
    }

    CommandAttribute UndoCmd::attribute()
    {
        return { "Undo", CommandAttribute::CommandType::kUndo };
    }

}