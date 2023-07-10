#include "geometry_factory.h"

#include "geometry_point_2d.h"
#include "geometry_line_2d.h"
#include "geometry_circle_2d.h"
#include "geometry_point_3d.h"
#include "geometry_line_3d.h"
#include "geometry_circle_3d.h"
#include "geometry_plane.h"

namespace EB
{

    Geometry* GeFactory::create(Geometry::eGeometryType type)
    {
        switch (type)
        {
            case EB::Geometry::eGeometryType::kPoint2d:           return new GePoint2d();
            case EB::Geometry::eGeometryType::kLine2d:            return new GeLine2d();
            case EB::Geometry::eGeometryType::kCircle2d:          return new GeCircle2d();
            case EB::Geometry::eGeometryType::kPoint3d:           return new GePoint3d();
            case EB::Geometry::eGeometryType::kLine3d:            return new GeLine3d();
            case EB::Geometry::eGeometryType::kCircle3d:          return new GeCircle3d();
            case EB::Geometry::eGeometryType::kPlane:             return new GePlane();
        }
        return nullptr;
    }

}