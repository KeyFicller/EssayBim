#include "gui_text_input_widget_impl.h"

namespace EB
{

    TextInputWidgetImpl::TextInputWidgetImpl(BaseWidget* pFacde, const std::string& name, std::string& editStr)
        : BaseWidgetImpl(pFacde, name), m_EditStr(editStr)
    {

    }

    TextInputWidgetImpl::~TextInputWidgetImpl()
    {
        EB_SAFE_ARRAY_DELETE(m_Buff);
    }

    void TextInputWidgetImpl::beginInteract()
    {
        if (m_Buff == nullptr) {
            m_MaxInputSize = EB_FACADE(TextInputWidget)->maxInputSize();
            m_Buff = new char[m_MaxInputSize];
        }
        memset(m_Buff, '\0', m_MaxInputSize);
        memcpy_s(m_Buff, m_MaxInputSize, m_EditStr.data(), m_EditStr.size() + 1);
    }

    void TextInputWidgetImpl::endInteract()
    {
        m_EditStr = m_Buff;
    }

    std::string& TextInputWidgetImpl::editStr()
    {
        return m_EditStr;
    }

    char* TextInputWidgetImpl::editBuff()
    {
        return m_Buff;
    }

}