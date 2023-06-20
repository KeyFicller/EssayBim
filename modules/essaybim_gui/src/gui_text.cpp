#include "gui_text.h"

#include "gui_text_impl.h"

namespace EB
{

    Text::Text(const std::string& name)
        : BaseWidget(name)
    {

    }

    Text::Text(const char* fmt, ...)
        : BaseWidget(* new TextImpl(this, ""))
    {
        va_list _args;
        __crt_va_start(_args, fmt);
        char buff[256];
        _vsprintf_s_l(buff, 256, fmt, 0, _args);
        __crt_va_end(_args);
        EB_IMPL(Text)->fmtStr() = buff;
    }

    Text::Text(TextImpl& impl)
        : BaseWidget(impl)
    {

    }

    bool Text::subOnImguiRender()
    {
        if (EB_IMPL(Text)->fmtStr().empty()) {
            ImGui::Text(EB_IMPL()->name().c_str());
        }
        else {
            ImGui::Text(EB_IMPL(Text)->fmtStr().c_str());
        }
        return false;
    }

    ColoredText::ColoredText(const Vec4& color, const std::string& name)
        : Text(name), m_Color(color)
    {

    }

    ColoredText::ColoredText(const Vec4& color, const char* fmt, ...)
        : Text(* new TextImpl(this, "")), m_Color(color)
    {
        va_list _args;
        __crt_va_start(_args, fmt);
        char buff[256];
        _vsprintf_s_l(buff, 256, fmt, 0, _args);
        __crt_va_end(_args);
        EB_IMPL(Text)->fmtStr() = buff;
    }

    bool ColoredText::subOnImguiRender()
    {
        if (EB_IMPL(Text)->fmtStr().empty()) {
            ImGui::TextColored(m_Color, EB_IMPL()->name().c_str());
        }
        else {
            ImGui::TextColored(m_Color, EB_IMPL(Text)->fmtStr().c_str());
        }
        return false;
    }

    GrayText::GrayText(const std::string& name)
        : Text(name)
    {

    }

    GrayText::GrayText(const char* fmt, ...)
        : Text(* new TextImpl(this, ""))
    {
        va_list _args;
        __crt_va_start(_args, fmt);
        char buff[256];
        _vsprintf_s_l(buff, 256, fmt, 0, _args);
        __crt_va_end(_args);
        EB_IMPL(Text)->fmtStr() = buff;
    }

    bool GrayText::subOnImguiRender()
    {
        if (EB_IMPL(Text)->fmtStr().empty()) {
            ImGui::TextDisabled(EB_IMPL()->name().c_str());
        }
        else {
            ImGui::TextDisabled(EB_IMPL(Text)->fmtStr().c_str());
        }
        return false;
    }

}