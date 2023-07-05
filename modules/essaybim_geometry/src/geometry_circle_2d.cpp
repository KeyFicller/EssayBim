#include "geometry_circle_2d.h"

#include "geometry_arithmetic.h"
#include "geometry_utils.h"
#include "geometry_circle_3d.h"

namespace EB
{
    EB_YAML_DECLARE_KEYS(Center, Radius);

    GeCricle2d::GeCricle2d()
    {

    }

    GeCricle2d::GeCricle2d(const GePoint2d& ptCenter, float radius)
        : m_PtCenter(ptCenter), m_Radius(radius)
    {

    }

    Geometry::eGeometryType GeCricle2d::geometryType() const
    {
        return eGeometryType::kCircle2d;
    }

    Geometry2d::Geometry* GeCricle2d::copy() const
    {
        return new GeCricle2d(m_PtCenter, m_Radius);
    }

    float GeCricle2d::paramAtPoint(const GePoint2d& pt) const
    {
        EB_CORE_ASSERT(isPointOnCurve(pt));
        return (pt - m_PtCenter).angleTo();
    }

    GePoint2d GeCricle2d::pointAtParam(float param) const
    {
        auto [min, max] = paramRange();
        EB_CORE_ASSERT(param >= min && param <= max);
        return GeVector2d(m_Radius, 0.0f).rotated(param).asGePoint2d();
    }

    std::pair<float, float> GeCricle2d::paramRange() const
    {
        return { 0.0f, 3.1415926f * 2.0f };
    }

    bool GeCricle2d::isPointOnCurve(const GePoint2d& pt) const
    {
        return GeUtils::underTolerance(pt.distanceTo(m_PtCenter) - m_Radius);
    }

    GeCurve3d* GeCricle2d::create3D(const GePlane& plane) const
    {
        GePoint3d pt3dCenter = GePoint3d(m_PtCenter.x(), m_PtCenter.y(), 0.0f).transformedBy(plane.planeToWorldMatrix());
        GeVector3d vec3dRef = GeVector3d(1.0f, 0.0f, 0.0f);
        return new GeCricle3d(pt3dCenter, m_Radius, plane.normal(), plane.planeToWorldMatrix() * vec3dRef);
    }

    void GeCricle2d::subYamlIn(const std::string& key)
    {
        GeCurve2d::subYamlIn(key);

        m_PtCenter.yamlIn(s_Key.Center);
        EB_YAML_IN(s_Key.Radius, m_Radius);
    }

    void GeCricle2d::subYamlOut(const std::string& key)
    {
        GeCurve2d::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        m_PtCenter.yamlOut(s_Key.Center);
        EB_YAML_OUT(s_Key.Radius, m_Radius);
    }

    GePoint2d GeCricle2d::center() const
    {
        return m_PtCenter;
    }

    float GeCricle2d::radius() const
    {
        return m_Radius;
    }

    void GeCricle2d::setCenter(const GePoint2d& ptCenter)
    {
        m_PtCenter = ptCenter;
    }

    void GeCricle2d::setRadius(float fRadius)
    {
        EB_CORE_ASSERT(fRadius >= 0.f);
        m_Radius = fRadius;
    }

}