int ismirror(BinaryTreeNode<int>* left,BinaryTreeNode<int>* right){
    

    if(left==NULL || right==NULL) return left==right;

        if(left->data!=right->data)
        {
            return 0;
        }  
        return ismirror(left->left,right->right)&& ismirror(left->right,right->left);      

}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root == NULL){
        return 1;
    }
    ismirror(root->left,root->right);
}
