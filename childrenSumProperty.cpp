#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int helper(BinaryTreeNode<int> *root){
    if(!root)return 0;
    if(!root->left and !root->right){
        root->data=1000000;
        return root->data;
    }
    int l=helper(root->left);
    int r=helper(root->right);
    root->data=(l+r);
    return root->data;

}
void changeTree(BinaryTreeNode < int > * root) {
    helper(root);
}  
