#include "essaybim_delete_cmd.h"

#include "essaybim_test_layer.h"

#include "database_database.h"

namespace EB
{
    // Notes:  I have stored some data from DeleteCmd::isRunnable
    namespace
    {
        Handle g_DelHandle;
    }

    DeleteCmd::DeleteCmd()
    {

    }

    DeleteCmd::~DeleteCmd()
    {

    }

    void DeleteCmd::beginInvoke()
    {
        CommandBase::beginInvoke();
        TestLayer::currentDb().remove(g_DelHandle);
    }

    EditorBase* DeleteCmd::editor()
    {
        return nullptr;
    }

    CommandAttribute DeleteCmd::attribute()
    {
        return { "Delete", CommandAttribute::CommandType::kNormal };
    }

    bool DeleteCmd::isRunnable(Layer* pLayer) const
    {
        TestLayer* pTestLayer = dynamic_cast<TestLayer*>(pLayer);
        EB_CORE_ASSERT(pTestLayer);
        if (pTestLayer->pickedEntity != -1) {
            g_DelHandle = Handle(pTestLayer->pickedEntity);
            return true;
        }
        return false;
    }

}