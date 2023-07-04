#pragma once

#include "geometry_base_3d.h"

namespace EB
{
    class GeMatrix3d;

    class EB_GEOMETRY_EXPORT GePoint3d : public Geometry3d
    {
    public:
        static const GePoint3d kOrigin;
    public:
        GePoint3d();
        GePoint3d(float x, float y, float z);

    public:
        eGeometryType geometryType() const override;
        Geometry* copy() const override;

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
        float distanceTo(const GePoint3d& ptOther) const;
        GePoint3d& transformBy(const GeMatrix3d& mat);
        GePoint3d transformedBy(const GeMatrix3d& mat) const;

    protected:
        float m_X = 0.0;
        float m_Y = 0.0;
        float m_Z = 0.0;
    };
}