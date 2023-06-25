#include "gui_image_widget.h"

#include "gui_base_widget_impl.h"
#include "gui_text.h"

#include <imgui.h>

#pragma warning(disable: 26451)
#pragma warning(disable: 4312)

namespace EB
{

    ImageWidget::ImageWidget(unsigned int textureId, const Vec2f& size)
        : BaseWidget(), m_TextureId(textureId), m_Size(size)
    {

    }

    bool ImageWidget::subOnImguiRender()
    {
        m_CursorPos = ImGui::GetCursorScreenPos();
        ImGui::Image((void*)m_TextureId, m_Size, Vec2f(0.0f, 1.0f), Vec2f(1.0f, 0.0f));
        return true;
    }

    ImageWidgetWithMagnifier::ImageWidgetWithMagnifier(unsigned int textureId, const Vec2f& size, float zoomScale /*= 4.0f*/)
        : ImageWidget(textureId, size), m_ZoomScale(zoomScale)
    {

    }

    void ImageWidgetWithMagnifier::postAction()
    {
        ImGuiIO& io = ImGui::GetIO();
        if (ImGui::IsItemHovered() && ImGui::BeginTooltip()) {
            
            float subSizeX = 128.f;
            float subSizeY = subSizeX / m_Size.x() * m_Size.y();
            float subPosX = io.MousePos.x - m_CursorPos.x() - subSizeX * 0.5f;
            float subPosY = io.MousePos.y - m_CursorPos.y() - subSizeY * 0.5f;
            if (subPosX < 0.0f) {
                subPosX = 0.0f;
            }
            else if (subPosX > m_Size.x() - subSizeX) {
                subPosX = m_Size.x() - subSizeX;
            }
            if (subPosY < 0.0f) {
                subPosY = 0.0f;
            }
            else if (subPosY > m_Size.y() - subSizeY) {
                subPosY = m_Size.y() - subSizeY;
            }
            EB_WIDGET_IMMEDIATE(Text, "Min: (%.2f, %.2f)", subPosX, subPosY);
            EB_WIDGET_IMMEDIATE(Text, "Max: (%.2f, %.2f)", subPosX + subSizeX, subPosY + subSizeY);

            //Vec2 uv0 = Vec2((subPosX) / m_Size.x(), (subPosY + subSizeY) / m_Size.y());
            //Vec2 uv1 = Vec2((subPosX + subSizeX) / m_Size.x(), subPosY / m_Size.y());
            Vec2f uv0 = Vec2f((subPosX) / m_Size.x(), 1.0f - (subPosY) / m_Size.y());
            Vec2f uv1 = Vec2f((subPosX + subSizeX) / m_Size.x(), 1.0f - (subPosY + subSizeY) / m_Size.y());
            ImGui::Image((void*)m_TextureId, Vec2f(subSizeX * m_ZoomScale, subSizeY * m_ZoomScale), uv0, uv1);
            ImGui::EndTooltip();
        }
    }

}