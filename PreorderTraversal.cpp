#include <bits/stdc++.h> 
using namespace std;
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
vector<int> getPreOrderTraversal(TreeNode *root)
{
  vector < int > po;
  if (root == NULL)
    return po;

  stack < TreeNode * > s;
  s.push(root);

  while (!s.empty()) {
    TreeNode * tn = s.top();
    po.push_back(tn -> data);
    s.pop();
    if (tn -> right != NULL)
      s.push(tn -> right);
    if (tn -> left != NULL)
      s.push(tn -> left);
  }
  return po;

}
