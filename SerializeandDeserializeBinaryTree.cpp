#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode<int> class structure

    template <typename T>
    class TreeNode<int> {
       public:
        T data;
        TreeNode<int><T> *left;
        TreeNode<int><T> *right;

        TreeNode<int>(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

string serializeTree(TreeNode<int> *root)
{
  string str="";
  queue<TreeNode<int>*> q;
  if(root==NULL)
  return str;
  q.push(root);
  while(q.size()!=0){
      auto it=q.front();q.pop();
      if(it!=NULL){
          str+=to_string(it->data)+',';
          q.push(it->left);
          q.push(it->right);
      }
      else{
          str+="#,";
      }
  }
  return str;
}

TreeNode<int>* deserializeTree(string data)
{
        if(data.size()==0)
        return NULL;
        string s;
        stringstream str(data);
        queue<TreeNode<int>*> q;
        getline(str,s,',');
        TreeNode<int>* root=new TreeNode<int>(stoi(s));
        q.push(root);
        while(!q.empty()){
            TreeNode<int>* a=q.front();
            q.pop();
            getline(str,s,',');
            if(s=="#") a->left=NULL;
            else{
                a->left=new TreeNode<int>(stoi(s));
                q.push(a->left);
            }
            getline(str,s,',');
            if(s=="#") a->right=NULL;
            else{
                a->right=new TreeNode<int>(stoi(s));
                q.push(a->right);
            }
        }
        return root;
}



