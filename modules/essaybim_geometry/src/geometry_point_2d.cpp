#include "geometry_point_2d.h"

#include "geometry_vector_2d.h"
#include "geometry_plane.h"
#include "geometry_arithmetic.h"

namespace EB
{
    EB_YAML_DECLARE_KEYS(X, Y);

    const GePoint2d GePoint2d::kOrigin = GePoint2d();

    GePoint2d::GePoint2d()
    {

    }

    GePoint2d::GePoint2d(float x, float y)
        : m_X(x), m_Y(y)
    {

    }

    GePoint2d::GePoint2d(const Vec2f& vec)
        : m_X(vec.x()), m_Y(vec.y())
    {

    }

    Geometry::eGeometryType GePoint2d::geometryType() const
    {
        return eGeometryType::kPoint2d;
    }

    Geometry2d::Geometry* GePoint2d::copy() const
    {
        return new GePoint2d(m_X, m_Y);
    }

    void GePoint2d::subYamlIn(const std::string& key)
    {
        Geometry2d::subYamlIn(key);

        EB_YAML_IN(s_Key.X, m_X);
        EB_YAML_IN(s_Key.Y, m_Y);
    }

    void GePoint2d::subYamlOut(const std::string& key) const
    {
        Geometry2d::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        EB_YAML_OUT(s_Key.X, m_X);
        EB_YAML_OUT(s_Key.Y, m_Y);
    }

    void GePoint2d::dump(Filer* pFiler) const
    {
        pFiler->writeVec<Vec2f>(*this);
    }

    void GePoint2d::load(Filer* pFiler)
    {
        (*this) = pFiler->readVec<Vec2f>();
    }

    float& GePoint2d::x()
    {
        return m_X;
    }

    float GePoint2d::x() const
    {
        return m_X;
    }

    float& GePoint2d::y()
    {
        return m_Y;
    }

    float GePoint2d::y() const
    {
        return m_Y;
    }

    float GePoint2d::distanceTo(const GePoint2d& ptOther) const
    {
        return (ptOther - (*this)).length();
    }

    void GePoint2d::transformBy(const GeMatrix2d& mat)
    {
        auto tmp = mat * (*this);
        m_X = tmp.x();
        m_Y = tmp.y();
    }

    GePoint3d GePoint2d::to3D(GePlane plane) const
    {
        GePoint3d res = GePoint3d(m_X, m_Y, 0.f);
        return plane.planeToWorldMatrix() * res;
    }

    GePoint2d::operator Vec2f() const
    {
        return Vec2f(m_X, m_Y);
    }

    GePoint2d::operator Vec2f& ()
    {
        return *reinterpret_cast<Vec2f*>(intptr_t(this) + sizeof(nullptr));
    }

}