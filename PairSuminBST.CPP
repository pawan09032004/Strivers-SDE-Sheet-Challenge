#include <bits/stdc++.h> 
/**********************************************************
    Following is the Binary Tree Node structure:
    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
bool search(BinaryTreeNode<int> *root, int k)
{
    if(root==0)
    {
        return 0;
    }
    while(root!=0)
    {
        if(root->data==k)
        {
            return true;
        }
        if(root->data>k)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    return false;
}
void ino(BinaryTreeNode<int> *root,vector<int> &in)
{
    if(root==0)
    {
        return;
    }
    ino(root->left,in);
    in.push_back(root->data);
    ino(root->right,in);    
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    if(root==0)
    {
        return 0;
    }
    vector<int> in;
    ino(root,in);    
    int i=0,j=in.size()-1;
    while(i<j)
    {
        if(in[i]+in[j]==k)
        {
            return true;
        }
        else if(in[i]+in[j]>k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
    
}
