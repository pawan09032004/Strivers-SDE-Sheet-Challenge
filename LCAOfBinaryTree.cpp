#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* lca(TreeNode<int>* node,int x,int y){
    if(node==NULL || node->data==x || node->data==y)return node;

    TreeNode<int> *left=lca(node->left,x,y);
    TreeNode<int> *right=lca(node->right,x,y);

    if(left==NULL)return right;
    else if(right==NULL)return left;
    else return node;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
      TreeNode<int> *node=lca(root,x,y);
      return node->data;
}
