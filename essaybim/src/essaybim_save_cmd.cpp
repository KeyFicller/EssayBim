#include "essaybim_save_cmd.h"

#include "essaybim_test_layer.h"

#include "basic_file_server.h"
#include "basic_yaml_base.h"
#include "database_database.h"
#include "window_window.h"

namespace EB
{

    SaveCmd::SaveCmd()
    {

    }

    SaveCmd::~SaveCmd()
    {

    }

    void SaveCmd::beginInvoke()
    {
        CommandBase::beginInvoke();
        YamlServer::instance().startYamlOut();
        TestLayer::currentDb().yamlOut("Database");
        YamlServer::instance().endYamlOut(FileServer::saveFile("Db (*.eb)\0*.eb\0", Window::instance("DemoApp")->hwnd()));
    }

    EditorBase* SaveCmd::editor()
    {
        return nullptr;
    }

    CommandAttribute SaveCmd::attribute()
    {
        return { "Save", CommandAttribute::CommandType::kNormal };
    }

}