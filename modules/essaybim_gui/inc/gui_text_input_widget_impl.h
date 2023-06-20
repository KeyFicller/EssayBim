#include "gui_text_input_widget.h"

#include "gui_base_widget_impl.h"

namespace EB
{
    class TextInputWidgetImpl : public BaseWidgetImpl
    {
    public:
        TextInputWidgetImpl(BaseWidget* pFacde, const std::string& name, std::string& editStr);
        ~TextInputWidgetImpl() override;

    public:
        void beginInteract();
        void endInteract();
        std::string& editStr();
        char* editBuff();

    protected:
        std::string& m_EditStr;
        char* m_Buff = nullptr;
        unsigned int m_MaxInputSize = 256;
    };
}