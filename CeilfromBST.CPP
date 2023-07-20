#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

void help(BinaryTreeNode<int> *node, int x,BinaryTreeNode<int> *search)
{
    if(node==0)
    {
        return;
    }
    if(x<node->data)
    {
        if(node->left)
        {
            search=node->left;
        }
        help(node->left,x,search);
    }
    else
    {
        if(node->right)
        {
            search=node->right;
        }
        return help(node->right,x,search);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x){
    if(node==0)
    {
        return -1;
    }
    BinaryTreeNode<int> *root=node;
    int ceil=-1;
    while(root!=0)
    {
        if(root->data==x)
        {
            return root->data;
        }
        if(root->data<x)
        {
            root=root->right;
        }
        else
        {
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}
