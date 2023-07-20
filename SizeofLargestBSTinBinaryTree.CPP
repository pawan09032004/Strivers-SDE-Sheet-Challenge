#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

class info{
    public:
    int maxi;
    int mini;
    bool isbst;
    int size;
};
info largestBST(TreeNode<int>* root,int &maxsize)
{
    if(root==0)
    {
        return {INT_MIN,INT_MAX,true,0};
    }
    info ltree=largestBST(root->left,maxsize);
    info rtree=largestBST(root->right,maxsize);
    info ans;
    ans.size=ltree.size+rtree.size+1;
    ans.maxi=max(rtree.maxi,root->data);
    ans.mini=min(ltree.mini,root->data);
    if(ltree.isbst && rtree.isbst && root->data <rtree.mini && root->data >ltree.maxi)
    {
        ans.isbst=true;
    }
    else
    {
        ans.isbst=false;
    }
    if(ans.isbst)
    {
        maxsize=max(maxsize,ans.size);
    }
    return ans;
} 
int largestBST(TreeNode<int>* root) 
{
    int maxisize=0;
    info ans=largestBST(root,maxisize);
    return maxisize;
}
