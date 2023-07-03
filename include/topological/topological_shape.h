#pragma once

#include "topological_base.h"

namespace EB
{
    class TopoShapeImpl;

    class GeGeomtry;

    class EB_EXPORT TopoShape : public Topological
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
        GeGeomtry* geometry() const;
        void setGeometry(GeGeomtry* pGeom);

    public:
        void setBit(int bit, bool isOn = true);
        bool hasBit(int bit);
    };
}