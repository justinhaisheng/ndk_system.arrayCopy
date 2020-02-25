//
// Created by haisheng.lu on 2020/2/25.
//

#ifndef NDK_SYSTEM_ARRAYCOPY_TREENODE_HPP
#define NDK_SYSTEM_ARRAYCOPY_TREENODE_HPP

#endif //NDK_SYSTEM_ARRAYCOPY_TREENODE_HPP

template <class T>
class TreeNode{
public:
    T data;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(T data){
        this->data = data;
    }
    ~TreeNode(){
    }
};