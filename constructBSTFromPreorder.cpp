#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* helper(vector<int> &arr,int l,int r){
    if(l>r)return NULL;
    int num=arr[l];
    TreeNode<int>* root=new TreeNode<int>(num);
    // if(l==r)return root;
    int i=l+1;
    for(;i<=r;i++){
        if(arr[i]>num){
            break;
        }
    }
    root->left=helper(arr,l+1,i-1);
    root->right=helper(arr,i,r);
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    return helper(preOrder,0,preOrder.size()-1);
}
