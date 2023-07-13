#include "essaybim_load_cmd.h"

#include "essaybim_test_layer.h"

#include "basic_file_server.h"
#include "basic_yaml_base.h"
#include "database_database.h"
#include "window_window.h"

namespace EB
{

    LoadCmd::LoadCmd()
    {

    }

    LoadCmd::~LoadCmd()
    {

    }

    void LoadCmd::beginInvoke()
    {
        CommandBase::beginInvoke();
        YamlServer::instance().startYamlIn(FileServer::saveFile("Db (*.eb)\0*.eb\0", Window::instance("DemoApp")->hwnd()));
        TestLayer::currentDb().yamlIn("Database");
        YamlServer::instance().endYamlIn();
    }

    EditorBase* LoadCmd::editor()
    {
        return nullptr;
    }

    CommandAttribute LoadCmd::attribute()
    {
        return { "Load", CommandAttribute::CommandType::kNormal };
    }

}