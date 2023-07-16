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

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode <int> *curr = root;
    BinaryTreeNode <int> *head = NULL;
    BinaryTreeNode <int> *tail = NULL;

    while (curr != NULL) {
        if (curr -> left == NULL) {
            if (head == NULL) {
                head = curr;
                tail = curr;
            }
            else {
                tail -> right = curr;
                tail = tail -> right;
            }
            curr = curr -> right;
        }
        else {
            BinaryTreeNode <int> *prev = curr->left;
            while (prev -> right && prev -> right != curr) {
                prev = prev -> right;
            }
            if (prev -> right == NULL) {
                prev -> right = curr;
                curr = curr -> left;
            }
            else {
                tail -> right = curr;
                tail = tail -> right;
                curr = curr -> right;
            }
        }
    }

    curr = head;
    BinaryTreeNode <int> *prev2 = NULL;
    while (curr) {
        curr->left = prev2;
        prev2 = curr;
        curr = curr->right;
    }

    return head;

}
