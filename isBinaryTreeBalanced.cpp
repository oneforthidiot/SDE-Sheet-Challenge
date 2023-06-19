#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int rec(BinaryTreeNode<int> *root,int &ans){
    if(!root)return 0;
    int l=rec(root->left,ans);
    int r=rec(root->right,ans);
    ans=max(ans,(abs(l-r)));
    return 1+max(l,r);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    int ans=0;
    rec(root,ans);
    return ans<=1;
}
