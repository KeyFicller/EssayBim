#pragma once

#include "topological_base.h"

namespace EB
{
    class TopoShapeImpl;

    class Geometry;

    class EB_TOPOLOGICAL_EXPORT TopoShape : public Topological
    {
    public:
        enum class eTopoShapeType
        {
            kVertex,
            kEdge,
            kCoEdge,
            kLoop,
            kWrie,
            kFace,
            kSubShell,
            kShell,
            kCompound,
            kBody
        };

    public:
        TopoShape();
        TopoShape(TopoShapeImpl& impl);
        ~TopoShape() override = default;

    public:
        virtual eTopoShapeType shapeType() const = 0;
        Geometry* geometry() const;
        void setGeometry(Geometry* pGeom);

    public:
        void setBit(int bit, bool isOn = true);
        bool hasBit(int bit);
    };
}