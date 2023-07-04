#include "geometry_line_2d.h"

#include "geometry_arithmetic.h"
#include "geometry_utils.h"

namespace EB
{

    EB_YAML_DECLARE_KEYS(Start, End);

    GeLine2d::GeLine2d()
    {

    }

    GeLine2d::GeLine2d(const GePoint2d& ptStart, const GePoint2d& ptEnd)
        : m_PtStart(ptStart), m_PtEnd(ptEnd)
    {

    }

    Geometry::eGeometryType GeLine2d::geometryType() const
    {
        return eGeometryType::kLine2d;
    }

    Geometry2d::Geometry* GeLine2d::copy() const
    {
        return new GeLine2d(m_PtStart, m_PtEnd);
    }

    float GeLine2d::paramAtPoint(const GePoint2d& pt) const
    {
        EB_CORE_ASSERT(isPointOnCurve(pt));
        return (pt.distanceTo(m_PtStart)) / (asGeVector2d().length());
    }

    GePoint2d GeLine2d::pointAtParam(float param) const
    {
        auto [min, max] = paramRange();
        EB_CORE_ASSERT(param >= min && param <= max);
        return m_PtStart + (asGeVector2d().scale(param));
    }

    std::pair<float, float> GeLine2d::paramRange() const
    {
        return { 0.0f, 1.0f };
    }

    bool GeLine2d::isPointOnCurve(const GePoint2d& pt) const
    {
        GeVector2d v1 = pt - m_PtEnd;
        GeVector2d v2 = pt - m_PtStart;
        if (!v1.isParallelTo(v2)) {
            return false;
        }
        return GeUtils::inRange(pt.x(), m_PtStart.x(), m_PtEnd.x()) &&
               GeUtils::inRange(pt.y(), m_PtStart.y(), m_PtEnd.y());
    }

    void GeLine2d::subYamlIn(const std::string& key)
    {
        GeCurve2d::subYamlIn(key);

        m_PtStart.yamlIn(s_Key.Start);
        m_PtEnd.yamlIn(s_Key.End);
    }

    void GeLine2d::subYamlOut(const std::string& key)
    {
        GeCurve2d::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        m_PtStart.yamlOut(s_Key.Start);
        m_PtStart.yamlOut(s_Key.End);
    }

    GePoint2d GeLine2d::start() const
    {
        return m_PtStart;
    }

    GePoint2d GeLine2d::end() const
    {
        return m_PtEnd;
    }

    void GeLine2d::setStart(const GePoint2d& ptStart)
    {
        m_PtStart = ptStart;
    }

    void GeLine2d::setEnd(const GePoint2d& ptEnd)
    {
        m_PtEnd = ptEnd;
    }

    GeVector2d GeLine2d::asGeVector2d() const
    {
        return m_PtEnd - m_PtStart;
    }

}