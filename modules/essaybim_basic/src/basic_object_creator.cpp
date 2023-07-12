#include "basic_object_creator.h"

namespace EB
{

    namespace
    {
        std::map<std::string, ObjectCreator::createFunc> m_CreateFuncs;
    }

    void ObjectCreator::registerCreation(const std::string& className, const createFunc& func)
    {
        m_CreateFuncs[className] = func;
    }

}