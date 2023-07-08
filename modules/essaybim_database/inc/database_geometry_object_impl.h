#pragma once

#include "database_geometry_object.h"
#include "database_object_impl.h"

namespace EB
{
    class DbGeometryImpl : public DbObjectImpl
    {
    public:
        DbGeometryImpl(DbObject* pFacade);
        ~DbGeometryImpl() override;

    public:
        Geometry* geometry() const;
        void setGeometry(Geometry* pGeom);

    public:
        void onRender() const override;
        DbObject* clone() const override;
        void serialize(Filer* pFiler) const override;
        void deSerialize(Filer* pFiler) override;

    public:
        Geometry* m_pGeometry = nullptr;
    };
}