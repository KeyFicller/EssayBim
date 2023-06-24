#include "gui_tree_node_impl.h"

namespace EB
{

    TreeNodeImpl::TreeNodeImpl(BaseWidget* pFacade, const std::string& name)
        : BaseWidgetImpl(pFacade, name)
    {

    }

    bool TreeNodeImpl::isRoot() const
    {
        return !m_Parent;
    }

    bool TreeNodeImpl::isLeaf() const
    {
        return m_Childs.empty();
    }

    void TreeNodeImpl::addChild(const Shared<TreeNode>& treeNode)
    {
        if (std::find(m_Childs.begin(), m_Childs.end(), treeNode) == m_Childs.end()) {
            m_Childs.push_back(treeNode);
            m_Childs.back()->setParent(treeNode);
        }
    }

    void TreeNodeImpl::removeChild(const Shared<TreeNode>& treeNode)
    {
        if (std::find(m_Childs.begin(), m_Childs.end(), treeNode) != m_Childs.end()) {
            m_Childs.erase(std::find(m_Childs.begin(), m_Childs.end(), treeNode));
            treeNode->setParent(nullptr);
        }
    }

    void TreeNodeImpl::setParent(const Shared<TreeNode>& treeNode)
    {
        m_Parent = treeNode;
    }

    const std::vector<Shared<TreeNode>>& TreeNodeImpl::childs() const
    {
        return m_Childs;
    }

}