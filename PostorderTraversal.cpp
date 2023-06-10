#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPostOrderTraversal(TreeNode *root) {
     vector < int > po;
     if (root == NULL) {
       return po;
     }

        stack < TreeNode * > s1;
        stack < TreeNode * > s2;
        s1.push(root);
        while (!s1.empty()) {
            root = s1.top();
            s1.pop();
            s2.push(root);
            if (root->left != NULL) {
              s1.push(root->left);
            }
            if (root->right != NULL) {
              s1.push(root->right);
            }
        }
        while (!s2.empty()) {
          po.push_back(s2.top()->data);
          s2.pop();
        }
        return po;
}
