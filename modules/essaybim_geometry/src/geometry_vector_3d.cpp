#include "geometry_vector_3d.h"

#include "geometry_arithmetic.h"
#include "geometry_point_3d.h"
#include "geometry_utils.h"

namespace EB
{
    EB_YAML_DECLARE_KEYS(X, Y, Z);

    const GeVector3d GeVector3d::kXAxis = GeVector3d(1.0f, 0.0f, 0.0f);

    const GeVector3d GeVector3d::kYAxis = GeVector3d(0.0f, 1.0f, 0.0f);

    const GeVector3d GeVector3d::kZAxis = GeVector3d(0.0f, 0.0f, 1.0f);

    GeVector3d::GeVector3d()
    {

    }

    GeVector3d::GeVector3d(float x, float y, float z)
        : m_X(x), m_Y(y), m_Z(z)
    {

    }

    void GeVector3d::subYamlIn(const std::string& key)
    {
        YamlBase::subYamlIn(key);

        EB_YAML_IN(s_Key.X, m_X);
        EB_YAML_IN(s_Key.Y, m_Y);
        EB_YAML_IN(s_Key.Z, m_Z);
    }

    void GeVector3d::subYamlOut(const std::string& key)
    {
        YamlBase::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        EB_YAML_OUT(s_Key.X, m_X);
        EB_YAML_OUT(s_Key.Y, m_Y);
        EB_YAML_OUT(s_Key.Z, m_Z);
    }

    float& GeVector3d::x()
    {
        return m_X;
    }

    float GeVector3d::x() const
    {
        return m_X;
    }

    float& GeVector3d::y()
    {
        return m_Y;
    }

    float GeVector3d::y() const
    {
        return m_Y;
    }

    float& GeVector3d::z()
    {
        return m_Z;
    }

    float GeVector3d::z() const
    {
        return m_Z;
    }

    float GeVector3d::length() const
    {
        return sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z);
    }

    GeVector3d& GeVector3d::normalize()
    {
        float len = length();
        m_X /= len;
        m_Y /= len;
        m_Z /= len;
        return *this;
    }

    GeVector3d GeVector3d::normalized() const
    {
        float len = length();
        return GeVector3d(m_X / len, m_Y / len, m_Z / len);
    }

    GeVector3d& GeVector3d::scale(float factor /*= 1.0f*/)
    {
        m_X *= factor;
        m_Y *= factor;
        m_Z *= factor;
        return *this;
    }

    GeVector3d GeVector3d::scaled(float factor /*= 1.0f*/) const
    {
        return (*this) * factor;
    }

    float GeVector3d::dot(const GeVector3d& other) const
    {
        return m_X * other.m_X + m_Y * other.m_Y + m_Z * other.m_Z;
    }

    GeVector3d GeVector3d::cross(const GeVector3d& other) const
    {
        return GeVector3d(
            m_Y * other.m_Z - other.m_Y * m_Z,
            other.m_X * m_Z - other.m_Z * m_X,
            m_X * other.m_Y - other.m_X * m_Y
        );
    }

    float GeVector3d::angleTo(const GeVector3d& other, const GeVector3d& ref) const
    {
        GeVector3d fixedRef;
        if (ref.isPerpendicularTo(*this) && ref.isPerpendicularTo(other)) {
            fixedRef = ref;
        }
        else {
            fixedRef = (*this).cross(other);
        }

        bool invert = (*this).cross(other).x() * fixedRef.x() < 0.f;
        float cosTheta = dot(other) / length() / other.length();
        float sinTheta = cross(other).length() / length() / other.length();
        float rotateRad = sinTheta >= 0.0f ? (float)acos(cosTheta) : (float)(EB_TWOPI - acos(cosTheta));
        return invert ? (EB_TWOPI - rotateRad) : rotateRad;
    }

    bool GeVector3d::isParallelTo(const GeVector3d& other) const
    {
        return GeUtils::underTolerance(cross(other).length());
    }

    bool GeVector3d::isPerpendicularTo(const GeVector3d& other) const
    {
        return GeUtils::underTolerance(dot(other));
    }

    GePoint3d GeVector3d::asGePoint3d() const
    {
        return GePoint3d(m_X, m_Y, m_Z);
    }

}