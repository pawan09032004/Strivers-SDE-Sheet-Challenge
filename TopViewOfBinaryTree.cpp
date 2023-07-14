#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    if(!root) return {};

    map<int, int> nodes; // {lvl, value}
    queue<pair<TreeNode<int>*, int>> q; // {node, {hD, level}}

    q.push({root, 0});

    while (!q.empty()) {
        auto qFront = q.front();
        q.pop();

        auto node = qFront.first;
        int hd = qFront.second;

        if(nodes.find(hd) == nodes.end())
            nodes[hd] = node->val;

        if(node->left) {
            q.push({node->left, hd-1});
        }

        if(node->right) {
            q.push({node->right, hd+1});
        }
    }

    vector<int> result;

    for (auto it : nodes) {
        result.push_back(it.second);
    }

    return result;
}
