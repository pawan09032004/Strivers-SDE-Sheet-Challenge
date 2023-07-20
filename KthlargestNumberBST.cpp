#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };
************************************************************/
int help(TreeNode<int> *root, int k,int &cnt)
{
    if(root==0)
    {
        return -1;
    }
    int l=help(root->left,k,cnt);
    if(l!=-1)
    {
        return l;
    }
    cnt++;
    if(cnt==k)
    {
        return root->data;
    }
    return help(root->right,k,cnt);
}
int num(TreeNode<int>* root)
{
    if(root==0)
    {
        return 0;
    }
    return 1+num(root->left)+num(root->right);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int nodes=num(root);
    int cnt=0;
    return help(root,nodes-k+1,cnt);
}
