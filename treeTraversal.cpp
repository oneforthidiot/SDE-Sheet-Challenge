#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void in1(BinaryTreeNode<int> *root,vector<int> &arr){
    if(!root)return;
    in1(root->left,arr);
    arr.push_back(root->data);
    in1(root->right,arr);
}
void pre(BinaryTreeNode<int> *root,vector<int> &arr){
    if(!root)return;
    arr.push_back(root->data);
    pre(root->left,arr);
    pre(root->right,arr);
}
void post(BinaryTreeNode<int> *root,vector<int> &arr){
    if(!root)return;
    post(root->left,arr);
    post(root->right,arr);
    arr.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int> arr1,arr2,arr3;
    in1(root,arr1);
    pre(root,arr2);
    post(root,arr3);
    return {arr1,arr2,arr3};
}
