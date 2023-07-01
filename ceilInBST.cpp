#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

void rec(BinaryTreeNode<int> *root,int x,int &ans){
    if(!root)return;
    if(root->data<x){
        rec(root->right,x,ans);
    }
    else
    if(root->data>=x){
        ans=root->data;
        rec(root->left,x,ans);
    }
    return;
}
int findCeil(BinaryTreeNode<int> *node, int x){
    int ans=-1;
    rec(node,x,ans);
    return ans;
}
