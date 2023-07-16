#include<bits/stdc++.h>
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* find(int start, int end, const vector<int>&inOrder, const vector<int>&postOrder,
                    const unordered_map<int, int>& mp, int& idx) {
    if (start > end) return nullptr;
    if (idx < 0) return nullptr;

    TreeNode<int>* root = new TreeNode<int>(postOrder[idx--]);
    int mid = mp.at(root->data);
    if (start == end) return root;
  root->right = find(mid + 1, end, inOrder, postOrder, mp, idx);
    root->left = find(start, mid - 1, inOrder, postOrder, mp, idx);
    return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
      int n = inOrder.size();
    if (n != postOrder.size()) return nullptr;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[inOrder[i]] = i;

    int idx = n-1;
    int start = 0, end = n - 1;
    return find(start, end, inOrder, postOrder, mp, idx);
}
