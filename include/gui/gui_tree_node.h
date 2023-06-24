#pragma once

#include "gui_base_widget.h"

namespace EB
{
    /**
     * @brief  this class defines tree node.
     */
    class EB_EXPORT TreeNode : public BaseWidget
    {
        friend class TreeNodeImpl;
    public:
        /**
         * @brief  constructor for tree node.
         * @param[in]    name      name of tree node.
         * @param[in]    slot      main function on tree node opened.
         */
        TreeNode(const std::string& name, const WidgetSlot& slot = nullptr);

    public:
        /**
         * @brief  get tree node is root.
         * @return   whether tree node is root.
         */
        bool isRoot() const;
        
        /**
         * @brief  get tree node is leaf.
         * @return   whether tree node is leaf.
         */
        bool isLeaf() const;

        /**
         * @brief  add child to this tree node.
         * @param[in]   treeNode    shared pointer to child node.
         */
        void addChild(const Shared<TreeNode>& treeNode);

        /**
         * @brief  remove child from this tree node.
         * @param[in]   treeNode    shared pointer to child node.
         */
        void removeChild(const Shared<TreeNode>& treeNode);

    protected:
        /**
         * @brief  set parent to this tree node.
         * @param[in]   treeNode    shared pointer to parent node.
         */
        void setParent(const Shared<TreeNode>& treeNode);
        
        /**
         * @brief   render gui and get triggered status.
         * @return  whether widget is triggered.
         */
        bool subOnImguiRender() override;

        /**
         * @brief   restore stack data after rendering.
         */
        void postAction() override;
    };
}