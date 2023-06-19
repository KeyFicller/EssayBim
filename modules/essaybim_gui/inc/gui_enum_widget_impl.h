#pragma once

#include "gui_base_widget_impl.h"

#include <string>

namespace EB
{
    class EnumWidgetImpl : public BaseWidgetImpl
    {
    public:
        EnumWidgetImpl(BaseWidget* pFacade, const std::string& name, int& index, const std::vector<std::string>& items);
        ~EnumWidgetImpl() override;

    public:
        const std::vector<const char*>& itemCStrs() const;
        const std::vector<std::string>& itemStrs() const;
        int& index() const;

    protected:
        int& m_Index;
        std::vector<std::string> m_ItemStrs;
        std::vector<const char*> m_ItemCStrs;
    };
}