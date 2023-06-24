#include "gui_drag_and_drop.h"

#include "basic_assert.h"
#include "basic_filer.h"

#include <imgui.h>

#include <map>

namespace EB
{
    namespace {
        std::map<std::string, Filer> s_FilerMap;
    }

    DragAndDropBase::DragAndDropBase(const std::string& label)
        : BaseWidget(), m_Label(label)
    {

    }

    DragSource::DragSource(const std::string& label, const EncodeFunc& encode)
        : DragAndDropBase(label), m_Encode(encode)
    {
        setSlot([&]() {
            s_FilerMap[m_Label].clear();
            m_Encode(&s_FilerMap[m_Label]);
            ImGui::SetDragDropPayload(m_Label.c_str(), nullptr, 0);
        });
    }

    bool DragSource::subOnImguiRender()
    {
        return ImGui::BeginDragDropSource();
    }

    void DragSource::postAction()
    {
        ImGui::EndDragDropSource();
    }

    DropTarget::DropTarget(const std::string& label, const DecodeFunc& decode)
        : DragAndDropBase(label), m_Decode(decode)
    {
        setSlot([&]() {
            if (ImGui::AcceptDragDropPayload(m_Label.c_str())) {
                EB_CORE_ASSERT(s_FilerMap.find(m_Label) != s_FilerMap.end());
                s_FilerMap[m_Label].seek(0);
                m_Decode(&s_FilerMap[m_Label]);
            }
        });
    }

    bool DropTarget::subOnImguiRender()
    {
        return ImGui::BeginDragDropTarget();
    }

    void DropTarget::postAction()
    {
        ImGui::EndDragDropTarget();
    }

}