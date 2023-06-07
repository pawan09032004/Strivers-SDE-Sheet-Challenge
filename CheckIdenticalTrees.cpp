bool identicalTrees(BinaryTreeNode<int>* p, BinaryTreeNode<int>* q) {
    if(!p && !q){
        return 1;
    }

    if (p && q) {
      return (p->data == q->data) && identicalTrees(p->left, q->left) &&
             identicalTrees(p->right, q->right);
    }
    return 0;
}
