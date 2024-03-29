#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    sort(preOrder.begin(), preOrder.end());

    TreeNode<int> *node = new TreeNode<int>(preOrder[0]);

    TreeNode<int> *curr = node;

    for (int i = 1; i < preOrder.size(); i++)
    {

        TreeNode<int> *temp = new TreeNode<int>(preOrder[i]);

        curr->right = temp;

        curr = curr->right;
    }

    return node;
}
