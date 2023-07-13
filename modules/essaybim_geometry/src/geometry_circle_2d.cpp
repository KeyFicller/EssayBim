#include "geometry_circle_2d.h"

#include "geometry_arithmetic.h"
#include "geometry_utils.h"
#include "geometry_circle_3d.h"

namespace EB
{
    EB_YAML_DECLARE_KEYS(Center, Radius);

    GeCircle2d::GeCircle2d()
    {

    }

    GeCircle2d::GeCircle2d(const GePoint2d& ptCenter, float radius, const GeVector2d& ref)
        : m_PtCenter(ptCenter), m_Radius(radius), m_Ref(ref)
    {
        m_Ref.normalize().scale(radius);
    }

    Geometry::eGeometryType GeCircle2d::geometryType() const
    {
        return eGeometryType::kCircle2d;
    }

    Geometry2d::Geometry* GeCircle2d::copy() const
    {
        return new GeCircle2d(m_PtCenter, m_Radius);
    }

    float GeCircle2d::paramAtPoint(const GePoint2d& pt) const
    {
        EB_CORE_ASSERT(isPointOnCurve(pt));
        return (pt - m_PtCenter).angleTo() * EB_RAD2PARAM;
    }

    GePoint2d GeCircle2d::pointAtParam(float param) const
    {
        auto [min, max] = paramRange();
        EB_CORE_ASSERT(param >= min && param <= max);
        return GeVector2d(m_Radius, 0.0f).rotated(param * EB_PARAM2RAD).asGePoint2d();
    }

    std::pair<float, float> GeCircle2d::paramRange() const
    {
        return { 0.0f, 1.0f };
    }

    bool GeCircle2d::isPointOnCurve(const GePoint2d& pt) const
    {
        return GeUtils::underTolerance(pt.distanceTo(m_PtCenter) - m_Radius);
    }

    GeCurve3d* GeCircle2d::create3D(const GePlane& plane) const
    {
        GePoint3d pt3dCenter = GePoint3d(m_PtCenter.x(), m_PtCenter.y(), 0.0f).transformedBy(plane.planeToWorldMatrix());
        GeVector3d vec3dRef = GeVector3d(m_Ref.x(), m_Ref.y(), 0.0f);
        return new GeCircle3d(pt3dCenter, m_Radius, plane.normal(), plane.planeToWorldMatrix() * vec3dRef);
    }

    void GeCircle2d::transformBy(const GeMatrix2d& mat)
    {
        m_PtCenter.transformBy(mat);
        m_Ref.transformBy(mat);
        m_Radius = m_Ref.length();
    }

    GePoint2d GeCircle2d::closestPointTo(const GePoint2d& pt) const
    {
        return m_PtCenter + (pt - m_PtCenter).normalize().scale(m_Radius);
    }

    void GeCircle2d::subYamlIn(const std::string& key)
    {
        GeCurve2d::subYamlIn(key);

        m_PtCenter.yamlIn(s_Key.Center);
        EB_YAML_IN(s_Key.Radius, m_Radius);
    }

    void GeCircle2d::subYamlOut(const std::string& key) const
    {
        GeCurve2d::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        m_PtCenter.yamlOut(s_Key.Center);
        EB_YAML_OUT(s_Key.Radius, m_Radius);
    }

    void GeCircle2d::dump(Filer* pFiler) const
    {
        m_PtCenter.dump(pFiler);
        pFiler->writeFloat(m_Radius);
        m_Ref.dump(pFiler);
    }

    void GeCircle2d::load(Filer* pFiler)
    {
        m_PtCenter.load(pFiler);
        m_Radius = pFiler->readFloat();
        m_Ref.load(pFiler);
    }

    GePoint2d GeCircle2d::center() const
    {
        return m_PtCenter;
    }

    float GeCircle2d::radius() const
    {
        return m_Radius;
    }

    void GeCircle2d::setCenter(const GePoint2d& ptCenter)
    {
        m_PtCenter = ptCenter;
    }

    void GeCircle2d::setRadius(float fRadius)
    {
        EB_CORE_ASSERT(fRadius >= 0.f);
        m_Radius = fRadius;
    }

}