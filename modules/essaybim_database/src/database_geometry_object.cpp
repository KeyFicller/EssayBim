#include "database_geometry_object.h"

#include "database_geometry_object_impl.h"

namespace EB
{

    DbGeometry::DbGeometry()
        : DbObject(*new DbGeometryImpl(this))
    {

    }

    DbGeometry::~DbGeometry()
    {

    }

    Geometry* DbGeometry::geometry() const
    {
        EB_DB_CHECK_WRITE_ENABLED();
        return EB_IMPL(DbGeometry)->geometry();
    }

    void DbGeometry::setGeometry(Geometry* pGeom)
    {
        EB_DB_CHECK_WRITE_ENABLED();
        EB_IMPL(DbGeometry)->setGeometry(pGeom);
    }

    void DbGeometry::onRender() const
    {
        EB_DB_CHECK_WRITE_ENABLED();
        EB_IMPL(DbGeometry)->onRender();
    }

    DbObject* DbGeometry::clone() const
    {
        EB_DB_CHECK_WRITE_ENABLED();
        return EB_IMPL(DbGeometry)->clone();
    }

    void DbGeometry::serialize(Filer* pFiler) const
    {
        EB_DB_CHECK_WRITE_ENABLED();
        return EB_IMPL(DbGeometry)->serialize(pFiler);
    }

    void DbGeometry::deSerialize(Filer* pFiler)
    {
        EB_DB_CHECK_WRITE_ENABLED();
        return EB_IMPL(DbGeometry)->deSerialize(pFiler);
    }

}