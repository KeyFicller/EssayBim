#include "gui_tree_node.h"

#include "gui_tree_node_impl.h"

#include "basic_assert.h"

#include <imgui.h>

namespace EB
{
    namespace {
        ImGuiTreeNodeFlags s_flags = ImGuiTreeNodeFlags_OpenOnArrow |
                                     ImGuiTreeNodeFlags_OpenOnDoubleClick |
                                     ImGuiTreeNodeFlags_SpanFullWidth;
    }


    TreeNode::TreeNode(const std::string& name, const WidgetSlot& slot /*= nullptr*/)
        : BaseWidget(* new TreeNodeImpl(this, name))
    {
        setSlot(slot);
    }

    bool TreeNode::isRoot() const
    {
        return EB_IMPL(TreeNode)->isRoot();
    }

    bool TreeNode::isLeaf() const
    {
        return EB_IMPL(TreeNode)->isLeaf();
    }

    void TreeNode::addChild(const Shared<TreeNode>& treeNode)
    {
        EB_IMPL(TreeNode)->addChild(treeNode);
    }

    void TreeNode::removeChild(const Shared<TreeNode>& treeNode)
    {
        EB_IMPL(TreeNode)->removeChild(treeNode);
    }

    void TreeNode::setParent(const Shared<TreeNode>& treeNode)
    {
        EB_CORE_ASSERT(isRoot());
        EB_IMPL(TreeNode)->setParent(treeNode);
    }

    bool TreeNode::subOnImguiRender()
    {
        return ImGui::TreeNodeEx(EB_IMPL()->name().c_str(), s_flags);
    }

    void TreeNode::postAction()
    {
        for (auto& treeNode : EB_IMPL(TreeNode)->childs()) {
            treeNode->onGuiRender();
        }
        ImGui::TreePop();
    }

}