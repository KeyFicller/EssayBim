#include "essaybim_create_plane.h"

#include "essaybim_test_layer.h"

#include "database_geometry_database.h"
#include "database_geometry_object.h"
#include "geometry_plane.h"

namespace EB
{

    CreatePlaneCmd::CreatePlaneCmd()
    {

    }

    CreatePlaneCmd::~CreatePlaneCmd()
    {

    }

    void CreatePlaneCmd::beginInvoke()
    {
        CommandBase::beginInvoke();
        DbGeometry* dbGeom = new DbGeometry;
        dbGeom->setGeometry(new GePlane());
        Handle hdl;
        TestLayer::currentDb().add(dbGeom, hdl);
    }

    EditorBase* CreatePlaneCmd::editor()
    {
        return nullptr;
    }

    CommandAttribute CreatePlaneCmd::attribute()
    {
        return { "Create Plane" , CommandAttribute::CommandType::kNormal };
    }

}