#include "gui_text_impl.h"

namespace EB
{

    TextImpl::TextImpl(BaseWidget* pFacade, const std::string& name)
        : BaseWidgetImpl(pFacade, name)
    {

    }

    std::string& TextImpl::fmtStr()
    {
        return m_FmtStr;
    }

}