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

bool validateBST(BinaryTreeNode<int> *root) {
    if (root == nullptr) return true;

    if (root -> left) {
        if (root -> left -> data > root -> data) return false;
        if (!validateBST(root -> left)) return false;
    } 

    if (root -> right) {
        if (root -> right -> data < root -> data) return false;
        if (!validateBST(root -> right)) return false;
    }

    return true;
    
}
