#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
  if(!root) return;
  queue<BinaryTreeNode<int> *> q;
  q.push(root);

  while(!q.empty()){
    int sz = q.size();
    vector<BinaryTreeNode<int>*> v;

    for(int i = 0; i < sz; i++){
      auto top = q.front(); q.pop();
      if(i != sz-1) top->next = q.front(); //ignore last node
      if(top->left) q.push(top->left);
      if(top->right) q.push(top->right);
    }

  }
}
