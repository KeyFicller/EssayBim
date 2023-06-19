#include "gui_enum_widget_impl.h"

namespace EB
{

    EnumWidgetImpl::EnumWidgetImpl(BaseWidget* pFacade, const std::string& name, int& index, const std::vector<std::string>& items)
        : BaseWidgetImpl(pFacade, name), m_Index(index), m_ItemStrs(items)
    {
        m_ItemCStrs.clear();
        for (auto& item : m_ItemStrs) {
            m_ItemCStrs.push_back(item.c_str());
        }
    }

    EnumWidgetImpl::~EnumWidgetImpl()
    {

    }

    const std::vector<const char*>& EnumWidgetImpl::itemCStrs() const
    {
        return m_ItemCStrs;
    }

    const std::vector<std::string>& EnumWidgetImpl::itemStrs() const
    {
        return m_ItemStrs;
    }

    int& EnumWidgetImpl::index() const
    {
        return m_Index;
    }

}