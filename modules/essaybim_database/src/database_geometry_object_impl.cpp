#include "database_geometry_object_impl.h"

#include "database_geometry_undo_controller.h"

#include "geometry_base.h"
#include "geometry_line_3d.h"
#include "geometry_circle_3d.h"
#include "renderer_batch_render.h"

namespace EB
{

    DbGeometryImpl::DbGeometryImpl(DbObject* pFacade)
        : DbObjectImpl(pFacade)
    {

    }

    DbGeometryImpl::~DbGeometryImpl()
    {
        EB_SAFE_DELETE(m_pGeometry);
    }

    Geometry* DbGeometryImpl::geometry() const
    {
        return m_pGeometry;
    }

    void DbGeometryImpl::setGeometry(Geometry* pGeom)
    {
        m_pGeometry = pGeom;
    }

    void DbGeometryImpl::subClose()
    {
        DbGeUndoController::instance().recallFiler(m_pFiler);
    }

    void DbGeometryImpl::onRender() const
    {
        if (m_pGeometry->geometryType() == Geometry::eGeometryType::kLine3d) {
            BatchRender::line(((GeLine3d*)(m_pGeometry))->start(), ((GeLine3d*)(m_pGeometry))->end());
        }
        else if (m_pGeometry->geometryType() == Geometry::eGeometryType::kCircle3d) {
            BatchRender::circle(((GeCircle3d*)(m_pGeometry))->center(), ((GeCircle3d*)(m_pGeometry))->radius(), ((GeCircle3d*)(m_pGeometry))->normal());
        }
    }

    DbObject* DbGeometryImpl::clone() const
    {
        auto newObj = new DbGeometry;
        newObj->setGeometry(m_pGeometry->copy());
        return newObj;
    }

    void DbGeometryImpl::serialize(Filer* pFiler) const
    {
        DbObjectImpl::serialize(pFiler);
        m_pGeometry->dump(pFiler);
    }

    void DbGeometryImpl::deSerialize(Filer* pFiler)
    {
        DbObjectImpl::deSerialize(pFiler);
        m_pGeometry->load(pFiler);
    }

}