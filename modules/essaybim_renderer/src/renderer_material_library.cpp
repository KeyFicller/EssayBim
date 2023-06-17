#include "renderer_material_library.h"

namespace EB
{
    EB_DECLARE_YAML_KEYS(Materials);

    Shared<Material> MaterialLibrary::material(const std::string& key)
    {
        return get(key);
    }

    void MaterialLibrary::add(const Shared<Material>& material)
    {
        BaseLibrary<Material>::add(material->Name, material);
    }

    void MaterialLibrary::remove(const Shared<Material>& material)
    {
        BaseLibrary<Material>::remove(material->Name);
    }

    void MaterialLibrary::subYamlIn(const std::string& key)
    {
        YamlBase::subYamlIn(key);
        removeAll();

        std::vector<Shared<Material>> mats;
        EB_YAML_IN_SEQ(s_Key.Materials, [&]() {
            mats.push_back(createShared<Material>());
            return mats.back().get();
        });

        for (auto mat : mats) {
            m_ItemMap[mat->Name] = mat;
        }
    }

    void MaterialLibrary::subYamlOut(const std::string& key)
    {
        YamlBase::subYamlOut(key);
        EB_YAML_AUTO_MAP();

        auto iter = m_ItemMap.begin();
        EB_YAML_OUT_SEQ(s_Key.Materials, [&]() {
            YamlBase* pYamlObj = nullptr;
            if (iter != m_ItemMap.end()) {
                pYamlObj = iter->second.get();
                iter++;
            }
            return pYamlObj;
        });
    }

}