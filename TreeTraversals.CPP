#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

void travel2(BinaryTreeNode<int> *root,vector<int> &ans)
{
    if(root==0)
    {
        return;
    }
    travel2(root->left,ans);
    travel2(root->right,ans);
    ans.push_back(root->data);
}
vector<int> post(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    travel2(root,ans);
    return ans;

    // Write your code here.
}
void travel1(BinaryTreeNode<int> *root,vector<int> &ans)
{
    if(root==0)
    {
        return;
    }
    ans.push_back(root->data);
    travel1(root->left,ans);
    travel1(root->right,ans);
}
vector<int> pre(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    travel1(root,ans);
    return ans;

    // Write your code here.
}
void travel(BinaryTreeNode<int> *root,vector<int> &ans)
{
    if(root==0)
    {
        return;
    }
    travel(root->left,ans);
    ans.push_back(root->data);
    travel(root->right,ans);
}
vector<int> getInOrderTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    travel(root,ans);
    return ans;

    // Write your code here.
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans;
    ans.push_back(getInOrderTraversal(root));
    ans.push_back(pre(root));
    ans.push_back(post(root));
    return ans;
    // Write your code here.
}
