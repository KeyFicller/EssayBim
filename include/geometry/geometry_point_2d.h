#pragma once

#include "geometry_base_2d.h"

namespace EB
{
    class GeMatrix2d;

    class EB_EXPORT GePoint2d : public Geometry2d
    {
    public:
        static const GePoint2d kOrigin;
    public:
        GePoint2d();
        GePoint2d(float x, float y);
        
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
        float x() const;
        float y() const;
        float distanceTo(const GePoint2d& ptOther) const;
        GePoint2d& transformBy(const GeMatrix2d& mat);
        GePoint2d transformedBy(const GeMatrix2d& mat) const;

    protected:
        float m_X = 0.0;
        float m_Y = 0.0;
    };
}