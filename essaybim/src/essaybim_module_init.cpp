#include "essaybim_module_init.h"

#include "essaybim_create_line_2d_cmd.h"
#include "essaybim_create_circle_2d_cmd.h"
#include "essaybim_create_plane.h"
#include "essaybim_undo_cmd.h"
#include "essaybim_redo_cmd.h"
#include "essaybim_delete_cmd.h"

#include "command_scheduler.h"
#include "command_undo_manager.h"
#include "database_geometry_undo_controller.h"

namespace EB
{
    namespace
    {
        class ModuleInit
        {
        public:
            ModuleInit()
            {
                CommandScheduler::instance().registerCommand(EB_CMD_CREATE_LINE_2D, []() {return new CreateLine2dCmd(); });
                CommandScheduler::instance().registerCommand(EB_CMD_CREATE_CIRCLE_2D, []() {return new CreateCircle2dCmd(); });
                CommandScheduler::instance().registerCommand(EB_CMD_CREATE_PLANE, []() {return new CreatePlaneCmd(); });
                CommandScheduler::instance().registerCommand(EB_CMD_UNDO, []() {return new UndoCmd(); });
                CommandScheduler::instance().registerCommand(EB_CMD_REDO, []() {return new RedoCmd(); });
                CommandScheduler::instance().registerCommand(EB_CMD_DELETE, []() {return new DeleteCmd(); });

                UndoManager::instance().addController(&DbGeUndoController::instance());
            }

            ~ModuleInit()
            {
                CommandScheduler::instance().unregisterCommand(EB_CMD_CREATE_LINE_2D);
                CommandScheduler::instance().unregisterCommand(EB_CMD_CREATE_CIRCLE_2D);
                CommandScheduler::instance().unregisterCommand(EB_CMD_CREATE_PLANE);
                CommandScheduler::instance().unregisterCommand(EB_CMD_UNDO);
                CommandScheduler::instance().unregisterCommand(EB_CMD_REDO);
                CommandScheduler::instance().unregisterCommand(EB_CMD_DELETE);
            }
        };

        static ModuleInit init;
    }
}