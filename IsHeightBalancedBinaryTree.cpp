#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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

*************************************************************/
bool isbalanced = true;

int height(BinaryTreeNode<int>* root){
    if(!root){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    if(isbalanced && abs(lh-rh)>1){
        isbalanced = false;
    }
    return max(lh,rh)+1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    height(root);
    bool temp = isbalanced;
    isbalanced = true;
    return temp;
}
