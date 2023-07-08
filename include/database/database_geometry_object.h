#pragma once

#include "database_object.h"

namespace EB
{
    /**
     * @
     */
    class EB_DATABASE_EXPORT DbGeometry : public DbObject
    {
    public:
        DbGeometry();
        ~DbGeometry();

    public:
        /**
         * @brief   deal with db object render.
         */
        void onRender() const override;

        /**
         * @brief   clone a same object.
         * @return    new created object.
         */
        DbObject* clone() const override;

        /**
         * @brief   serialize this object to an filer.
         * @param[in]      pFiler       filer to accept binary data.
         */
        void serialize(Filer* pFiler) const override;

        /**
         * @brief   deSerialize this object from an filer.
         * @param[in]      pFiler       filer to give binary data.
         */
        void deSerialize(Filer* pFiler) override;
    };
}