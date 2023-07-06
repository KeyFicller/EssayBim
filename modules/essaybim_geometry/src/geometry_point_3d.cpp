#include "geometry_point_3d.h"

#include "geometry_vector_3d.h"
#include "geometry_arithmetic.h"

namespace EB
{
    EB_YAML_DECLARE_KEYS(X, Y, Z);

    const GePoint3d GePoint3d::kOrigin = GePoint3d(0.f, 0.f, 0.f);

    GePoint3d::GePoint3d()
    {

    }

    GePoint3d::GePoint3d(float x, float y, float z)
        : m_X(x), m_Y(y), m_Z(z)
    {

    }

    Geometry::eGeometryType GePoint3d::geometryType() const
    {
        return eGeometryType::kPoint3d;
    }

    Geometry* GePoint3d::copy() const
    {
        return new GePoint3d(m_X, m_Y, m_Z);
    }

    void GePoint3d::subYamlIn(const std::string& key)
    {
        Geometry3d::subYamlIn(key);

        EB_YAML_IN(s_Key.X, m_X);
        EB_YAML_IN(s_Key.Y, m_Y);
        EB_YAML_IN(s_Key.Z, m_Z);
    }

    void GePoint3d::subYamlOut(const std::string& key)
    {
        Geometry3d::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        EB_YAML_OUT(s_Key.X, m_X);
        EB_YAML_OUT(s_Key.Y, m_Y);
        EB_YAML_OUT(s_Key.Z, m_Z);
    }

    float& GePoint3d::x()
    {
        return m_X;
    }

    float GePoint3d::x() const
    {
        return m_X;
    }

    float& GePoint3d::y()
    {
        return m_Y;
    }

    float GePoint3d::y() const
    {
        return m_Y;
    }

    float& GePoint3d::z()
    {
        return m_Z;
    }

    float GePoint3d::z() const
    {
        return m_Z;
    }

    float GePoint3d::distanceTo(const GePoint3d& ptOther) const
    {
        return (ptOther - (*this)).length();
    }

    GePoint3d& GePoint3d::transformBy(const GeMatrix3d& mat)
    {
        (*this) = transformedBy(mat);
        return *this;
    }

    GePoint3d GePoint3d::transformedBy(const GeMatrix3d& mat) const
    {
        return mat * (*this);
    }

    GePoint3d::operator Vec3f() const
    {
        return Vec3f(m_X, m_Y, m_Z);
    }

}