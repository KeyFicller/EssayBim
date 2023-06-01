#include "basic_yaml_base.h"
#include "basic_yaml_base_impl.h"

namespace EB
{

    YamlServer::YamlServer()
    {
        EB_IMPL = createScoped<YamlServerImpl>();
    }

    YamlServer::~YamlServer()
    {
    }

    YamlServer& YamlServer::instance()
    {
        static YamlServer server;
        return server;
    }

    void YamlServer::beginMap()
    {
        EB_IMPL->beginMap();
    }

    void YamlServer::endMap()
    {
        EB_IMPL->endMap();
    }

    void YamlServer::startYamlOut()
    {
        EB_IMPL->startYamlOut();
    }

    void YamlServer::endYamlOut(const std::string& filePath)
    {
        EB_IMPL->endYamlOut(filePath);
    }

    void YamlServer::startYamlIn(const std::string& filePath)
    {
        EB_IMPL->startYamlIn(filePath);
    }

    void YamlServer::endYamlIn()
    {
        EB_IMPL->endYamlIn();
    }

    bool YamlServer::hasKey(const std::string& key)
    {
        return EB_IMPL->hasKey(key);
    }

    void YamlServer::yamlIn(const std::string& key)
    {
        EB_IMPL->yamlIn(key);
    }

    void YamlServer::yamlIn(const std::string& key, bool& value)
    {
        EB_IMPL->yamlIn<bool>(key, value);
    }

    void YamlServer::yamlIn(const std::string& key, int& value)
    {
        EB_IMPL->yamlIn<int>(key, value);
    }

    void YamlServer::yamlIn(const std::string& key, float& value)
    {
        EB_IMPL->yamlIn<float>(key, value);
    }

    void YamlServer::yamlIn(const std::string& key, std::string& value)
    {
        EB_IMPL->yamlIn<std::string>(key, value);
    }

    void YamlServer::yamlIn(const std::string& key, Vec2& value)
    {
        EB_IMPL->yamlIn<Vec2>(key, value);
    }

    void YamlServer::yamlIn(const std::string& key, Vec3& value)
    {
        EB_IMPL->yamlIn<Vec3>(key, value);
    }

    void YamlServer::yamlIn(const std::string& key, Vec4& value)
    {
        EB_IMPL->yamlIn<Vec4>(key, value);
    }

    void YamlServer::yamlOut(const std::string& key)
    {
        EB_IMPL->yamlOut(key);
    }

    void YamlServer::yamlOut(const std::string& key, bool value)
    {
        EB_IMPL->yamlOut<bool>(key, value);
    }

    void YamlServer::yamlOut(const std::string& key, int value)
    {
        EB_IMPL->yamlOut<int>(key, value);
    }

    void YamlServer::yamlOut(const std::string& key, float value)
    {
        EB_IMPL->yamlOut<float>(key, value);
    }

    void YamlServer::yamlOut(const std::string& key, const std::string& value)
    {
        EB_IMPL->yamlOut<std::string>(key, value);
    }

    void YamlServer::yamlOut(const std::string& key, const Vec2& value)
    {
        EB_IMPL->yamlOut<Vec2>(key, value);
    }

    void YamlServer::yamlOut(const std::string& key, const Vec3& value)
    {
        EB_IMPL->yamlOut<Vec3>(key, value);
    }

    void YamlServer::yamlOut(const std::string& key, const Vec4& value)
    {
        EB_IMPL->yamlOut<Vec4>(key, value);
    }

    YamlBase::AutoMapWrapper::AutoMapWrapper()
    {
        YamlServer::instance().beginMap();
    }

    YamlBase::AutoMapWrapper::~AutoMapWrapper()
    {
        YamlServer::instance().endMap();
    }

    YamlBase::YamlBase()
    {
    }

    YamlBase::~YamlBase()
    {
    }

    void YamlBase::yamlIn(const std::string& key)
    {
        subYamlIn(key);
        YamlServer::instance().m_pImpl->popNode();
    }

    void YamlBase::yamlOut(const std::string& key)
    {
        subYamlOut(key);
    }

    void YamlBase::subYamlIn(const std::string& key)
    {
        YamlServer::instance().yamlIn(key);
    }

    void YamlBase::subYamlOut(const std::string& key)
    {
        YamlServer::instance().yamlOut(key);
    }

}