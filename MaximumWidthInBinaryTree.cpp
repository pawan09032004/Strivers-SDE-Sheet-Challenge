#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

int getMaxWidth(TreeNode<int> *root)
{
    if(!root) return 0;

    queue<TreeNode<int> *> q;
    q.push(root);

    int ans = 0;
    while(!q.empty()){
        int sz = q.size();
        ans = max(ans, sz);

        while(sz--){
            auto top = q.front();
            q.pop();
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
    }

    return ans;
}
