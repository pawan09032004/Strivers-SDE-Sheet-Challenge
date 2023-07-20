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

TreeNode <int> *buildTree (vector<int> &inorder, int inStart, int inEnd, vector<int> &preorder, int preStart, int preEnd, unordered_map <int, int> &inMap) {
    TreeNode <int> *root = new TreeNode <int> (preorder[preStart]);

    if (preStart>preEnd || inStart>inEnd) return NULL;

    int inRoot = inMap [root->data];
    int numsLeft = inRoot - inStart;

    root -> left = buildTree(inorder, inStart, inRoot-1, preorder, preStart+1, preStart+numsLeft, inMap);
    root -> right = buildTree(inorder, inRoot+1, inEnd, preorder, preStart+numsLeft+1, preEnd, inMap);

    return root;
}


TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n = inorder.size();
    unordered_map <int, int> inMap;
    for (int i=0; i<n; i++) inMap [inorder[i]] = i;
    return buildTree (inorder, 0, n-1, preorder, 0, n-1, inMap);
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    vector <int> inOrder;
    for (int i=0; i<preOrder.size(); i++) inOrder.push_back (preOrder[i]);

    sort (inOrder.begin(), inOrder.end());
    return buildBinaryTree(inOrder, preOrder);
}
