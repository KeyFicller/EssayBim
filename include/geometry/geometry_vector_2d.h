#pragma once

#include "basic_export.h"
#include "basic_yaml_base.h"

#include "geometry_point_2d.h"

namespace EB
{
    class EB_EXPORT GeVector2d : public YamlBase
    {
    public:
        static const GeVector2d kXAxis;
        static const GeVector2d kYAxis;

    public:
        GeVector2d();
        GeVector2d(float x, float y);

    protected:
        /**
         * @brief   interface for override import class data.
         * @param[in]    key    for yaml map.
         */
        void subYamlIn(const std::string& key) override;

        /**
         * @brief   interface for override export class data.
         * @param[in]    key    for yaml map.
         */
        void subYamlOut(const std::string& key) override;

    public:
        float& x();
        float& y();
        float x() const;
        float y() const;
        float length() const;
        GeVector2d& normalize();
        GeVector2d normalized() const;
        GeVector2d& scale(float factor = 1.0f);
        GeVector2d scaled(float factor = 1.0f) const;
        GeVector2d& rotate(float rad);
        GeVector2d rotated(float rad) const;
        float dot(const GeVector2d& other) const;
        float cross(const GeVector2d& other) const;
        float angleTo(const GeVector2d& other = kXAxis) const;
        bool isParallelTo(const GeVector2d& other) const;
        bool isPerpendicularTo(const GeVector2d& other) const;
        GePoint2d asGePoint2d() const;

    protected:
        float m_X = 0.0;
        float m_Y = 0.0;
    };
}