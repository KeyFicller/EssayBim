#pragma once

#include "basic_assert.h"
#include "basic_yaml_base.h"

#include <yaml-cpp/yaml.h>

#include <string>
#include <stack>
#include <functional>

namespace YAML
{
    template <>
    struct convert<EB::Vec2f>
    {
        static Node encode(const EB::Vec2f& rhs)
        {
            Node node;
            for (int i = 0; i < 2; i++) {
                node.push_back(rhs[i]);
            }
            return node;
        }

        static bool decode(const Node& node, EB::Vec2f& rhs)
        {
            if (!node.IsSequence() || node.size() != 2) {
                return false;
            }

            for (int i = 0; i < 2; i++) {
                rhs[i] = node[i].as<float>();
            }
            return true;
        }
    };

    template <>
    struct convert<EB::Vec3f>
    {
        static Node encode(const EB::Vec3f& rhs)
        {
            Node node;
            for (int i = 0; i < 3; i++) {
                node.push_back(rhs[i]);
            }
            return node;
        }

        static bool decode(const Node& node, EB::Vec3f& rhs)
        {
            if (!node.IsSequence() || node.size() != 3) {
                return false;
            }

            for (int i = 0; i < 3; i++) {
                rhs[i] = node[i].as<float>();
            }
            return true;
        }
    };

    template <>
    struct convert<EB::Vec4f>
    {
        static Node encode(const EB::Vec4f& rhs)
        {
            Node node;
            for (int i = 0; i < 4; i++) {
                node.push_back(rhs[i]);
            }
            return node;
        }

        static bool decode(const Node& node, EB::Vec4f& rhs)
        {
            if (!node.IsSequence() || node.size() != 4) {
                return false;
            }

            for (int i = 0; i < 4; i++) {
                rhs[i] = node[i].as<float>();
            }
            return true;
        }
    };
}

namespace EB
{
    YAML::Emitter& operator << (YAML::Emitter& out, const Vec2f& v);
    YAML::Emitter& operator << (YAML::Emitter& out, const Vec3f& v);
    YAML::Emitter& operator << (YAML::Emitter& out, const Vec4f& v);

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