#include "geometry_line_3d.h"

#include "geometry_arithmetic.h"
#include "geometry_utils.h"

namespace EB
{
    EB_YAML_DECLARE_KEYS(Start, End);

    GeLine3d::GeLine3d()
    {

    }

    GeLine3d::GeLine3d(const GePoint3d& ptStart, const GePoint3d& ptEnd)
        : m_PtStart(ptStart), m_PtEnd(ptEnd)
    {

    }

    Geometry::eGeometryType GeLine3d::geometryType() const
    {
        return eGeometryType::kLine3d;
    }

    Geometry3d::Geometry* GeLine3d::copy() const
    {
        return new GeLine3d(m_PtStart, m_PtEnd);
    }

    float GeLine3d::paramAtPoint(const GePoint3d& pt) const
    {
        EB_CORE_ASSERT(isPointOnCurve(pt));
        return (pt.distanceTo(m_PtStart)) / (asGeVector3d().length());
    }

    GePoint3d GeLine3d::pointAtParam(float param) const
    {
        auto [min, max] = paramRange();
        EB_CORE_ASSERT(param >= min && param <= max);
        return m_PtStart + (asGeVector3d().scale(param));
    }

    std::pair<float, float> GeLine3d::paramRange() const
    {
        return { 0.0f, 1.0f };
    }

    bool GeLine3d::isPointOnCurve(const GePoint3d& pt) const
    {
        GeVector3d v1 = pt - m_PtEnd;
        GeVector3d v2 = pt - m_PtStart;
        if (!v1.isParallelTo(v2)) {
            return false;
        }
        return GeUtils::inRange(pt.x(), m_PtStart.x(), m_PtEnd.x()) &&
               GeUtils::inRange(pt.y(), m_PtStart.y(), m_PtEnd.y()) &&
               GeUtils::inRange(pt.y(), m_PtStart.z(), m_PtEnd.z());
    }

    void GeLine3d::subYamlIn(const std::string& key)
    {
        GeCurve3d::subYamlIn(key);

        m_PtStart.yamlIn(s_Key.Start);
        m_PtEnd.yamlIn(s_Key.End);
    }

    void GeLine3d::subYamlOut(const std::string& key)
    {
        GeCurve3d::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        m_PtStart.yamlOut(s_Key.Start);
        m_PtStart.yamlOut(s_Key.End);
    }

    void GeLine3d::dump(Filer* pFiler) const
    {
        m_PtStart.dump(pFiler);
        m_PtEnd.dump(pFiler);
    }

    void GeLine3d::load(Filer* pFiler)
    {
        m_PtStart.load(pFiler);
        m_PtEnd.load(pFiler);
    }

    GePoint3d GeLine3d::start() const
    {
        return m_PtStart;
    }

    GePoint3d GeLine3d::end() const
    {
        return m_PtEnd;
    }

    void GeLine3d::setStart(const GePoint3d& ptStart)
    {
        m_PtStart = ptStart;
    }

    void GeLine3d::setEnd(const GePoint3d& ptEnd)
    {
        m_PtEnd = ptEnd;
    }

    GeVector3d GeLine3d::asGeVector3d() const
    {
        return m_PtEnd - m_PtStart;
    }

}