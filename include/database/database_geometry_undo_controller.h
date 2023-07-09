#pragma once

#include "database_export.h"

#include "command_undo_controller.h"

namespace EB
{
    /**
     * @brief  this enum defines object operation.
     */
    enum class DbGeUndoOpCode : int
    {
        /** < operation identify object added > */
        kObjectAdd,
        
        /** < operation identify object deleted > */
        kObjectDelete,
    };

    /**
     * @brief  undo controller for database geometry object.
     */
    class EB_DATABASE_EXPORT DbGeUndoController : public UndoController
    {
    public:
        /**
         * @brief   constructor for database geometry object.
         */
        DbGeUndoController();

        /**
         * @brief   destructor for database geometry object.
         */
        ~DbGeUndoController() override;

    public:
        /**
         * @brief   get instance of DbGeUndoController.
         * @return   global instance of DbGeUndoController;
         */
        static DbGeUndoController& instance();

    public:
        /**
         * @brief   get roll back functions for this controller.
         * @return       roll back functions.
         */
        const std::map<int, UndoFunc>& rollbackFuncs() const override;
    };
}