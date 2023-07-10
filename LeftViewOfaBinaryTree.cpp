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

void help(TreeNode<int> *node,vector<int>& ans,int level){
    if(node==NULL)return;
    if(level==ans.size())ans.push_back(node->data);
    help(node->left,ans,level+1);
    help(node->right,ans,level+1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    help(root,ans,0);
    return ans;    
}
