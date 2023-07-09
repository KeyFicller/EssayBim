#pragma once

#include "command_export.h"

#include "basic_impl_template.h"

#include <functional>
#include <map>

namespace EB
{
    class Filer;

    /**
     * @brief  this class defines UndoController Base.
     */
    class EB_COMMAND_EXPORT UndoController
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(UndoController)
    public:
        using UndoFunc = std::function<void(void*, Filer*)>;

    public:
        /**
         * @brief    constructor for UndoController.
         */
        UndoController();

        /**
         * @brief    destructor for UndoController.
         */
        virtual ~UndoController();

    public:
        /**
         * @brief   roll back filer to start position.
         * @param[in]    pFiler      roll back to filer.
         */
        void rollbackFiler(Filer* pFiler);

        /**
         * @brief   roll back object.
         * @param[in]    pObject     object pointer.
         * @param[in]    pFiler      filer.
         */
        void rollbackObject(void* pObject, Filer* pFiler);

        /**
         * @brief   roll back operation.
         * @param[in]    pObject     object pointer.
         * @param[in]    opCode      operation identify, defined at derive class.
         */
        void rollbackOperation(void* pObject, int opCode, Filer* pFiler);

        /**
         * @brief    commit filer data to global undo controller.
         * @param[in]    pFiler      filer.
         */
        void recallFiler(Filer* pFiler);

        /**
         * @brief   get roll back functions for this controller.
         * @return       roll back functions.
         */
        virtual const std::map<int, UndoFunc>& rollbackFuncs() const = 0;
    };
}