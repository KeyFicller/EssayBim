#include "basic_yaml_base_impl.h"

#include <fstream>

#define ERR_NO_EMITTER "Doesn't exisit a working emiiter."
#define ERR_HAS_EMITTER "Already has a working emitter."
#define ERR_EMPTY_STACK "Empty yaml node stack."
#define ERR_NOT_EMPTY_STACK "Not empty yaml node stack."
#define EB_CORE_ASSERT_HAS_EMMITER() EB_CORE_ASSERT(m_pCurEmitter, ERR_NO_EMITTER)
#define EB_CORE_ASSERT_NO_EMMITER() EB_CORE_ASSERT(!m_pCurEmitter, ERR_HAS_EMITTER)
#define EB_CORE_ASSERT_EMPTY_NODE_STACK() EB_CORE_ASSERT(m_CurNodeStack.empty(), ERR_NOT_EMPTY_STACK)
#define EB_CORE_ASSERT_NOT_EMPTY_NODE_STACK() EB_CORE_ASSERT(!m_CurNodeStack.empty(), ERR_EMPTY_STACK)

namespace EB
{
    YAML::Emitter& operator << (YAML::Emitter& out, const Vec2f& v)
    {
        out << YAML::Flow;
        out << YAML::BeginSeq;
        for (int i = 0; i < 2; i++) {
            out << v[i];
        }
        out << YAML::EndSeq;
        return out;
    }

    YAML::Emitter& operator << (YAML::Emitter& out, const Vec3f& v)
    {
        out << YAML::Flow;
        out << YAML::BeginSeq;
        for (int i = 0; i < 3; i++) {
            out << v[i];
        }
        out << YAML::EndSeq;
        return out;
    }

    YAML::Emitter& operator << (YAML::Emitter& out, const Vec4f& v)
    {
        out << YAML::Flow;
        out << YAML::BeginSeq;
        for (int i = 0; i < 4; i++) {
            out << v[i];
        }
        out << YAML::EndSeq;
        return out;
    }

    YamlServerImpl::YamlServerImpl()
        : m_pCurEmitter(nullptr)
    {
        while (!m_CurNodeStack.empty()) {
            m_CurNodeStack.pop();
        }
    }

    YamlServerImpl::~YamlServerImpl()
    {
        delete m_pCurEmitter;
    }

    void YamlServerImpl::beginMap()
    {
        EB_CORE_ASSERT_HAS_EMMITER();
        (*m_pCurEmitter) << YAML::BeginMap;
    }

    void YamlServerImpl::endMap()
    {
        EB_CORE_ASSERT_HAS_EMMITER();
        (*m_pCurEmitter) << YAML::EndMap;
    }

    void YamlServerImpl::startYamlOut()
    {
        EB_CORE_ASSERT_NO_EMMITER();
        m_pCurEmitter = new YAML::Emitter;
        beginMap();
    }

    void YamlServerImpl::endYamlOut(const std::string& filePath)
    {
        EB_CORE_ASSERT_HAS_EMMITER();
        endMap();
        std::ofstream fout(filePath);
        fout << m_pCurEmitter->c_str();
        fout.close();
        delete m_pCurEmitter;
        m_pCurEmitter = nullptr;
    }

    void YamlServerImpl::startYamlIn(const std::string& filePath)
    {
        EB_CORE_ASSERT_EMPTY_NODE_STACK();
        std::ifstream fin(filePath);
        std::stringstream ss;
        ss << fin.rdbuf();
        fin.close();

        m_CurNodeStack.push(YAML::Load(ss.str()));
    }

    void YamlServerImpl::endYamlIn()
    {
        EB_CORE_ASSERT(m_CurNodeStack.size() == 1);
        m_CurNodeStack.pop();
    }

    bool YamlServerImpl::hasKey(const std::string& key)
    {
        EB_CORE_ASSERT_NOT_EMPTY_NODE_STACK();
        YAML::Node& topNode = m_CurNodeStack.top();
        return topNode[key].IsDefined();
    }

    void YamlServerImpl::yamlOutSequence(const std::string& key, std::function<YamlBase* ()> func)
    {
        EB_CORE_ASSERT_HAS_EMMITER();
        (*m_pCurEmitter) << YAML::Key << key << YAML::Value;
        (*m_pCurEmitter) << YAML::BeginSeq;
        while (YamlBase* pYamlOutObj = func()) {
            pYamlOutObj->yamlOut("");
        }
        (*m_pCurEmitter) << YAML::EndSeq;
    }

    void YamlServerImpl::yamlInSequence(const std::string& key, std::function<YamlBase* ()> func)
    {
        EB_CORE_ASSERT_NOT_EMPTY_NODE_STACK();
        YAML::Node& topNode = m_CurNodeStack.top();
        YAML::Node& sequenceNode = topNode[key];
        EB_CORE_ASSERT(sequenceNode.IsDefined());
        for (auto& itemNode : sequenceNode) {
            m_CurNodeStack.push(itemNode);
            YamlBase* pYamlInObj = func();
            EB_CORE_ASSERT(pYamlInObj);
            pYamlInObj->yamlIn("");
        }
    }

    void YamlServerImpl::yamlOut(const std::string& key)
    {
        EB_CORE_ASSERT_HAS_EMMITER();
        if (key.size()) {
            (*m_pCurEmitter) << YAML::Key << key << YAML::Value;
        }
    }

    void YamlServerImpl::yamlIn(const std::string& key)
    {
        EB_CORE_ASSERT_NOT_EMPTY_NODE_STACK();
        if (key.size()) {
            YAML::Node& topNode = m_CurNodeStack.top();
            m_CurNodeStack.push(topNode[key]);
        }
    }

    void YamlServerImpl::popNode()
    {
        EB_CORE_ASSERT_NOT_EMPTY_NODE_STACK();
        m_CurNodeStack.pop();
    }

}