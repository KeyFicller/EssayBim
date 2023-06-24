#pragma once

#include "gui_base_widget_impl.h"

#include "gui_tree_node.h"

namespace EB
{
    class TreeNodeImpl : public BaseWidgetImpl
    {
    public:
        TreeNodeImpl(BaseWidget* pFacade, const std::string& name);

    public:
        bool isRoot() const;
        bool isLeaf() const;
        void addChild(const Shared<TreeNode>& treeNode);
        void removeChild(const Shared<TreeNode>& treeNode);
        void setParent(const Shared<TreeNode>& treeNode);
        const std::vector<Shared<TreeNode>>& childs() const;

    protected:
        Shared<TreeNode> m_Parent;
        std::vector<Shared<TreeNode>> m_Childs;
    };
}