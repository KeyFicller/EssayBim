#include "geometry_line_2d.h"

#include "geometry_arithmetic.h"
#include "geometry_utils.h"
#include "geometry_line_3d.h"

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

    GeCurve3d* GeLine2d::create3D(const GePlane& plane) const
    {
        GePoint3d pt3dStart = GePoint3d(m_PtStart.x(), m_PtStart.y(), 0.0f).transformedBy(plane.planeToWorldMatrix());
        GePoint3d pt3dEnd = GePoint3d(m_PtEnd.x(), m_PtEnd.y(), 0.0f).transformedBy(plane.planeToWorldMatrix());
        return new GeLine3d(pt3dStart, pt3dEnd);
    }

    void GeLine2d::transformBy(const GeMatrix2d& mat)
    {
        m_PtStart.transformBy(mat);
        m_PtEnd.transformBy(mat);
    }

    GePoint2d GeLine2d::closestPointTo(const GePoint2d& pt) const
    {
        GeVector2d vecLine = asGeVector2d().normalize();
        GeVector2d vecPt = (pt - m_PtStart);
        GePoint2d ptPrjOnLine = m_PtStart + vecLine.scale(vecPt.dot(vecLine));
        if (isPointOnCurve(ptPrjOnLine)) {
            return ptPrjOnLine;
        }
        return ptPrjOnLine.distanceTo(m_PtStart) > ptPrjOnLine.distanceTo(m_PtEnd) ?
            m_PtEnd : m_PtStart;
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

    void GeLine2d::dump(Filer* pFiler) const
    {
        m_PtStart.dump(pFiler);
        m_PtEnd.dump(pFiler);
    }

    void GeLine2d::load(Filer* pFiler)
    {
        m_PtStart.load(pFiler);
        m_PtEnd.load(pFiler);
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