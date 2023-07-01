#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void rec(TreeNode<int> *root,int x,int &ans){
    if(!root)return;
    if(root->val>x){
        return rec(root->left,x,ans);
    }
    else
    if(root->val<=x){
        ans=root->val;
        return rec(root->right,x,ans);
    }
    return;
}
int floorInBST(TreeNode<int> * root, int X){
    int ans=0;
    rec(root,X,ans);
    return ans;
}
