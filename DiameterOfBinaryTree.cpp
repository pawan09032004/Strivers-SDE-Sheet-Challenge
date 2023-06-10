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
    int d=0;
    int height(TreeNode<int>* root){
        if(root==NULL) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        int currd = lh + rh;

        int ans = max(lh,rh)+1;

        d = max(d,currd);
        
        return ans;
    }
    
int diameterOfBinaryTree(TreeNode<int> *root)
{
       
        height(root);
        int temp=d;
        d=0;
        return temp;
}
