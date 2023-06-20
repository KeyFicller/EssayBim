#pragma once

#include "gui_text.h"
#include "gui_base_widget_impl.h"

namespace EB
{
    class TextImpl : public BaseWidgetImpl
    {
    public:
        TextImpl(BaseWidget* pFacade, const std::string& name);

    public:
        std::string& fmtStr();

    protected:
        std::string m_FmtStr;
    };
}