#include "geometry_plane.h"

#include "geometry_matrix_3d.h"

namespace EB
{
    EB_YAML_DECLARE_KEYS(Origin, XAxis, YAxis);

    const GePlane GePlane::kXY = GePlane(GePoint3d::kOrigin, GeVector3d::kXAxis, GeVector3d::kYAxis);

    const GePlane GePlane::kYZ = GePlane(GePoint3d::kOrigin, GeVector3d::kYAxis, GeVector3d::kZAxis);

    const GePlane GePlane::kXZ = GePlane(GePoint3d::kOrigin, GeVector3d::kXAxis, GeVector3d::kZAxis);

    GePlane::GePlane()
    {

    }

    GePlane::GePlane(const GePoint3d& origin, const GeVector3d& xAxis, const GeVector3d& yAxis)
        : m_Origin(origin), m_XAxis(xAxis), m_YAxis(yAxis)
    {
        EB_CORE_ASSERT(xAxis.isPerpendicularTo(yAxis));
    }

    Geometry::eGeometryType GePlane::geometryType() const
    {
        return eGeometryType::kPlane;
    }

    Geometry3d::Geometry* GePlane::copy() const
    {
        return new GePlane(m_Origin, m_XAxis, m_YAxis);
    }

    void GePlane::subYamlIn(const std::string& key)
    {
        GeSurface::subYamlIn(key);

        m_Origin.yamlIn(s_Key.Origin);
        m_XAxis.yamlIn(s_Key.XAxis);
        m_YAxis.yamlIn(s_Key.YAxis);
    }

    void GePlane::subYamlOut(const std::string& key)
    {
        GeSurface::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        m_Origin.yamlOut(s_Key.Origin);
        m_XAxis.yamlOut(s_Key.XAxis);
        m_YAxis.yamlOut(s_Key.YAxis);
    }

    void GePlane::set(const GePoint3d& origin, const GeVector3d& xAxis, const GeVector3d& yAxis)
    {
        EB_CORE_ASSERT(xAxis.isPerpendicularTo(yAxis));
        m_Origin = origin;
        m_XAxis = xAxis;
        m_YAxis = yAxis;
    }

    GePoint3d GePlane::origin() const
    {
        return m_Origin;
    }

    GeVector3d GePlane::xAxis() const
    {
        return m_XAxis;
    }

    GeVector3d GePlane::yAxis() const
    {
        return m_YAxis;
    }

    GeVector3d GePlane::normal() const
    {
        return m_XAxis.cross(m_YAxis).normalized();
    }

    GeMatrix3d GePlane::planeToWorldMatrix() const
    {
        return GeMatrix3d().setAsPlaneMatrix(m_Origin, m_XAxis, m_YAxis).inverse();
    }

}