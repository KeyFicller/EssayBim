#include "geometry_line_2d.h"

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

}