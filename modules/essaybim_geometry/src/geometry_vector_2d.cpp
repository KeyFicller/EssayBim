#include "geometry_vector_2d.h"

#include "geometry_arithmetic.h"
#include "geometry_matrix_2d.h"
#include "geometry_point_2d.h"
#include "geometry_utils.h"

#include "basic_filer.h"

namespace EB
{
    EB_YAML_DECLARE_KEYS(X, Y);

    const GeVector2d GeVector2d::kXAxis = GeVector2d(1.0f, 0.0f);

    const GeVector2d GeVector2d::kYAxis = GeVector2d(0.0f, 1.0f);

    GeVector2d::GeVector2d()
    {

    }

    GeVector2d::GeVector2d(float x, float y)
        : m_X(x), m_Y(y)
    {

    }

    GeVector2d::GeVector2d(const Vec2f& vec)
        : m_X(vec.x()), m_Y(vec.y())
    {

    }

    void GeVector2d::subYamlIn(const std::string& key)
    {
        YamlBase::subYamlIn(key);

        EB_YAML_IN(s_Key.X, m_X);
        EB_YAML_IN(s_Key.Y, m_Y);
    }

    void GeVector2d::subYamlOut(const std::string& key) const
    {
        YamlBase::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        EB_YAML_OUT(s_Key.X, m_X);
        EB_YAML_OUT(s_Key.Y, m_Y);
    }

    void GeVector2d::dump(Filer* pFiler) const
    {
        pFiler->writeVec<Vec2f>(*this);
    }

    void GeVector2d::load(Filer* pFiler)
    {
        (*this) = pFiler->readVec<Vec2f>();
    }

    float& GeVector2d::x()
    {
        return m_X;
    }

    float GeVector2d::x() const
    {
        return m_X;
    }

    float& GeVector2d::y()
    {
        return m_Y;
    }

    float GeVector2d::y() const
    {
        return m_Y;
    }

    float GeVector2d::length() const
    {
        return sqrt(m_X * m_X + m_Y * m_Y);
    }

    GeVector2d& GeVector2d::normalize()
    {
        EB_CORE_ASSERT(length() > 1e-6);
        float len = length();
        m_X /= len;
        m_Y /= len;
        return *this;
    }

    GeVector2d GeVector2d::normalized() const
    {
        EB_CORE_ASSERT(length() > 1e-6);
        float len = length();
        return GeVector2d(m_X / len, m_Y / len);
    }

    GeVector2d& GeVector2d::scale(float factor /*= 1.0f*/)
    {
        m_X *= factor;
        m_Y *= factor;
        return *this;
    }

    GeVector2d GeVector2d::scaled(float factor /*= 1.0f*/) const
    {
        return GeVector2d(m_X * factor, m_Y * factor);
    }

    GeVector2d& GeVector2d::rotate(float rad)
    {
        (*this) = rotated(rad);
        return *this;
    }

    GeVector2d GeVector2d::rotated(float rad) const
    {
        GeMatrix2d mat = GeMatrix2d().setAsRotation(rad);
        return mat * (*this);
    }

    GeVector2d& GeVector2d::transformBy(const GeMatrix2d& mat)
    {
        (*this) = mat * (*this);
        return *this;
    }

    float GeVector2d::dot(const GeVector2d& other) const
    {
        return m_X * other.m_X + m_Y * other.m_Y;
    }

    float GeVector2d::cross(const GeVector2d& other) const
    {
        return m_X * other.m_Y - m_Y * other.m_X;
    }

    float GeVector2d::angleTo(const GeVector2d& other /*= kXAxis*/) const
    {
         float cosTheta = dot(other) / length() / other.length();
         float sinTheta = cross(other) / length() / other.length();
         return sinTheta >= 0.0f ? (float)acos(cosTheta) : (float)(EB_TWOPI - acos(cosTheta));
    }

    bool GeVector2d::isParallelTo(const GeVector2d& other) const
    {
        return GeUtils::underTolerance(cross(other));
    }

    bool GeVector2d::isPerpendicularTo(const GeVector2d& other) const
    {
        return GeUtils::underTolerance(dot(other));
    }

    GePoint2d GeVector2d::asGePoint2d() const
    {
        return GePoint2d(m_X, m_Y);
    }

    GeVector2d::operator Vec2f() const
    {
        return Vec2f(m_X, m_Y);
    }

    GeVector2d::operator Vec2f& ()
    {
        return *reinterpret_cast<Vec2f*>(intptr_t(this) + sizeof(nullptr));
    }

}