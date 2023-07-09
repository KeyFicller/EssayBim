#include "command_undo_manager.h"

#include "command_undo_manager_impl.h"

namespace EB
{

    UndoManager::UndoManager()
    {
        EB_IMPL() = createScoped<UndoManagerImpl>();
    }

    UndoManager::~UndoManager()
    {
        EB_IMPL().reset();
    }

    UndoManager& UndoManager::instance()
    {
        static UndoManager mgr;
        return mgr;
    }

    void UndoManager::beforeCommand(const CommandAttribute& attribute)
    {
        EB_IMPL()->beforeCommand(attribute);
    }

    void UndoManager::afterCommand()
    {
        EB_IMPL()->afterCommand();
    }

    void UndoManager::undo()
    {
        EB_IMPL()->undo();
    }

    void UndoManager::redo()
    {
        EB_IMPL()->redo();
    }

    void UndoManager::addController(UndoController* pController)
    {
        EB_IMPL()->addController(pController);
    }

    void UndoManager::recallFrom(UndoController* pController, Filer* pFiler)
    {
        EB_IMPL()->recallFrom(pController, pFiler);
    }

    std::vector<std::string> UndoManager::commandsInUndoStack() const
    {
        return EB_IMPL()->commandsInUndoStack();
    }

    std::vector<std::string> UndoManager::commandsInRedoStack() const
    {
        return EB_IMPL()->commandsInRedoStack();
    }

}