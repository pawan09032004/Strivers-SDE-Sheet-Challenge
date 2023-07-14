#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> *root) {
    map<int, map<int, list<int>>> nodes; // {hDist -> {level, [values]}}
    queue<pair<BinaryTreeNode<int>*, pair<int, int>>> q; // {node, {hD, level}}

    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto qFront = q.front();
        q.pop();

        auto node = qFront.first;
        int hd = qFront.second.first;
        int lvl = qFront.second.second;

        nodes[hd][lvl].push_back(node->data);

        if (node->left) {
            q.push({node->left, {hd - 1, lvl + 1}});
        }

        if (node->right) {
            q.push({node->right, {hd + 1, lvl + 1}});
        }
    }

    vector<int> result;

    for (auto it : nodes) {
        // last level of every horizontal distance
        auto lastLevel = (--it.second.end())->second;
        // --it because we want to access the last element of the map
        // last element of last level of every horizontal distance is bottom view
        result.push_back(lastLevel.back());
    }

    return result;
}

