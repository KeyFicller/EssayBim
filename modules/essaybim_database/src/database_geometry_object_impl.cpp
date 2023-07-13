#include "database_geometry_object_impl.h"

#include "database_geometry_undo_controller.h"

#include "basic_file_server.h"
#include "geometry_base.h"
#include "geometry_circle_3d.h"
#include "geometry_factory.h"
#include "geometry_line_3d.h"
#include "geometry_plane.h"
#include "renderer_batch_render.h"
#include "renderer_texture.h"

namespace EB
{
    EB_YAML_DECLARE_KEYS(GeometryType, GeometryData);

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
        BatchRender::pushObjectId(m_Handle);
        if (m_pGeometry->geometryType() == Geometry::eGeometryType::kLine3d) {
            BatchRender::line(((GeLine3d*)(m_pGeometry))->start(), ((GeLine3d*)(m_pGeometry))->end());
        }
        else if (m_pGeometry->geometryType() == Geometry::eGeometryType::kCircle3d) {
            BatchRender::circle(((GeCircle3d*)(m_pGeometry))->center(), ((GeCircle3d*)(m_pGeometry))->radius(), ((GeCircle3d*)(m_pGeometry))->normal());
        }
        else if (m_pGeometry->geometryType() == Geometry::eGeometryType::kPlane) {
            static int g_PlaneTextureId = BatchRender::addTexture(
                Texture2D::create(FileServer::resourcesPathRoot() + "\\textures\\grid.png")
            );
            BatchRender::pushTransparency(0.8f);
            BatchRender::pushTextureId(g_PlaneTextureId);
            GePlane* pPlane = (GePlane*)m_pGeometry;
            BatchRender::quad(pPlane->origin(), pPlane->xAxis(), pPlane->yAxis());
            BatchRender::popTextureId();
            BatchRender::popTransparency();
        }
        BatchRender::popObjectId();
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
        pFiler->writeInt(static_cast<int>(m_pGeometry->geometryType()));
        m_pGeometry->dump(pFiler);
    }

    void DbGeometryImpl::deSerialize(Filer* pFiler)
    {
        DbObjectImpl::deSerialize(pFiler);
        Geometry::eGeometryType type = static_cast<Geometry::eGeometryType>(pFiler->readInt());
        EB_SAFE_DELETE(m_pGeometry);
        m_pGeometry = GeFactory::create(type);
        m_pGeometry->load(pFiler);
    }

    void DbGeometryImpl::subYamlIn(const std::string& key)
    {
        int type;
        EB_YAML_IN(s_Key.GeometryType, type);
        EB_SAFE_DELETE(m_pGeometry);
        m_pGeometry = GeFactory::create((Geometry::eGeometryType)type);
        m_pGeometry->yamlIn(s_Key.GeometryData);
    }

    void DbGeometryImpl::subYamlOut(const std::string& key) const
    {
        EB_YAML_OUT(s_Key.GeometryType, (int)m_pGeometry->geometryType());
        m_pGeometry->yamlOut(s_Key.GeometryData);
    }

}