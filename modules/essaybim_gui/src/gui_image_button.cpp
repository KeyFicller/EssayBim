#include "gui_image_button.h"

#include "gui_base_widget_impl.h"

#include <imgui.h>

#pragma warning(disable: 4312)

namespace EB
{

    ImageButton::ImageButton(unsigned int textureId, const Vec2f& size, const WidgetSlot& slot /*= nullptr*/)
        : Button("", size,  slot), m_TextureId(textureId)
    {

    }

    bool ImageButton::subOnImguiRender()
    {
        return ImGui::ImageButton(reinterpret_cast<void*>(m_TextureId), m_Size, Vec2f(0.f, 1.0f), Vec2f(1.0f, 0.0f));
    }

}