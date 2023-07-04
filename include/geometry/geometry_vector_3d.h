#pragma once

#include "geometry_export.h"
#include "basic_yaml_base.h"

#include "geometry_point_3d.h"

namespace EB
{
    class EB_GEOMETRY_EXPORT GeVector3d : public YamlBase
    {
    public:
        static const GeVector3d kXAxis;
        static const GeVector3d kYAxis;
        static const GeVector3d kZAxis;

    public:
        GeVector3d();
        GeVector3d(float x, float y, float z);

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
        float& z();
        float x() const;
        float y() const;
        float z() const;
        float length() const;
        GeVector3d& normalize();
        GeVector3d normalized() const;
        GeVector3d& scale(float factor = 1.0f);
        GeVector3d scaled(float factor = 1.0f) const;
        float dot(const GeVector3d& other) const;
        GeVector3d cross(const GeVector3d& other) const;
        bool isParallelTo(const GeVector3d& other) const;
        bool isPerpendicularTo(const GeVector3d& other) const;
        GePoint3d asGePoint3d() const;

    protected:
        float m_X = 0.0;
        float m_Y = 0.0;
        float m_Z = 0.0;
    };
}