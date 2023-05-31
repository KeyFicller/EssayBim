#pragma once

#include "basic_assert.h"
#include "basic_yaml_base.h"

#include <yaml-cpp/yaml.h>

#include <string>
#include <stack>
#include <functional>

namespace EB
{
    class YamlServerImpl
    {
        friend class YamlBase;
    public:
        YamlServerImpl();
        ~YamlServerImpl();

    public:
        void beginMap();
        void endMap();
        void startYamlOut();
        void endYamlOut(const std::string& filePath);
        void startYamlIn(const std::string& filePath);
        void endYamlIn();
        bool hasKey(const std::string& key);
        void yamlOutSequence(const std::string& key, std::function<YamlBase*()> func);
        void yamlInSequence(const std::string& key, std::function<YamlBase*()> func);

        void yamlOut(const std::string& key);
        void yamlIn(const std::string& key);

        template <typename T>
        void yamlOut(const std::string& key, const T& value)
        {
            EB_CORE_ASSERT(m_pCurEmitter);
            (*m_pCurEmitter) << YAML::Key << key << YAML::Value << value;
        }
        template <typename T>
        void yamlIn(const std::string& key, T& value)
        {
            EB_CORE_ASSERT(m_CurNodeStack.size());
            YAML::Node& topNode = m_CurNodeStack.top();
            value = topNode[key].as<T>();
        }

    protected:
        void popNode();

    private:
        YAML::Emitter* m_pCurEmitter = nullptr;
        std::stack<YAML::Node> m_CurNodeStack;
    };
}