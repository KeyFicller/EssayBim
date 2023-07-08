#include "geometry_circle_3d.h"

#include "geometry_arithmetic.h"
#include "geometry_utils.h"
#include "geometry_matrix_3d.h"

namespace EB
{
    EB_YAML_DECLARE_KEYS(Center, Radius, Normal);

    GeCircle3d::GeCircle3d()
    {

    }

    GeCircle3d::GeCircle3d(const GePoint3d& ptCenter, float radius, const GeVector3d& normal, const GeVector3d& ref)
        : m_PtCenter(ptCenter), m_Radius(radius), m_Normal(normal), m_Ref(ref)
    {
        if (!m_Normal.isPerpendicularTo(m_Ref)) {
            // auto calculation for reference vector
            GeVector3d tmp[3] = { GeVector3d::kXAxis, GeVector3d::kYAxis, GeVector3d::kZAxis };
            for (int i = 0; i < 3; i++) {
                if (!m_Normal.isPerpendicularTo(tmp[i])) {
                    m_Ref = m_Normal.cross(tmp[i]);
                }
            }
        }
        m_Ref.normalize().scale(m_Radius);
    }

    Geometry::eGeometryType GeCircle3d::geometryType() const
    {
        return eGeometryType::kCircle3d;
    }

    Geometry3d::Geometry* GeCircle3d::copy() const
    {
        return new GeCircle3d(m_PtCenter, m_Radius, m_Normal);
    }

    float GeCircle3d::paramAtPoint(const GePoint3d& pt) const
    {
        EB_CORE_ASSERT(isPointOnCurve(pt));
        return (pt - m_PtCenter).angleTo(m_Ref, m_Normal) * EB_RAD2PARAM;
    }

    GePoint3d GeCircle3d::pointAtParam(float param) const
    {
        auto [min, max] = paramRange();
        EB_CORE_ASSERT(param >= min && param <= max);
        GeVector3d vec = GeMatrix3d().setAsRotation(param * EB_PARAM2RAD, m_Normal) * m_Ref;
        return m_PtCenter + vec;
    }

    std::pair<float, float> GeCircle3d::paramRange() const
    {
        return { 0.0f, 1.0f };
    }

    bool GeCircle3d::isPointOnCurve(const GePoint3d& pt) const
    {
        if (!(pt - m_PtCenter).isPerpendicularTo(m_Normal)) {
            return false;
        }
        return GeUtils::underTolerance(pt.distanceTo(m_PtCenter) - m_Radius);
    }

    void GeCircle3d::subYamlIn(const std::string& key)
    {
        GeCurve3d::subYamlIn(key);

        m_PtCenter.yamlIn(s_Key.Center);
        EB_YAML_IN(s_Key.Radius, m_Radius);
        m_Normal.yamlIn(s_Key.Normal);
    }

    void GeCircle3d::subYamlOut(const std::string& key)
    {
        GeCurve3d::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        m_PtCenter.yamlOut(s_Key.Center);
        EB_YAML_OUT(s_Key.Radius, m_Radius);
        m_Normal.yamlOut(s_Key.Normal);
    }

    void GeCircle3d::dump(Filer* pFiler) const
    {
        m_PtCenter.dump(pFiler);
        pFiler->writeFloat(m_Radius);
        m_Ref.dump(pFiler);
        m_Normal.dump(pFiler);
    }

    void GeCircle3d::load(Filer* pFiler)
    {
        m_PtCenter.load(pFiler);
        m_Radius = pFiler->readFloat();
        m_Ref.load(pFiler);
        m_Normal.load(pFiler);
    }

    GePoint3d GeCircle3d::center() const
    {
        return m_PtCenter;
    }

    float GeCircle3d::radius() const
    {
        return m_Radius;
    }

    GeVector3d GeCircle3d::normal() const
    {
        return m_Normal;
    }

    void GeCircle3d::setCenter(const GePoint3d& ptCenter)
    {
        m_PtCenter = ptCenter;
    }

    void GeCircle3d::setRadius(float fRadius)
    {
        m_Radius = fRadius;
    }

    void GeCircle3d::setNormal(const GeVector3d& vecNorm)
    {
        m_Normal = vecNorm;
    }

}