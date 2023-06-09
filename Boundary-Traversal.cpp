#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void left(TreeNode<int>* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(!root->left && !root->right){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        left(root->left,ans);
    }
    else if(root->right){
        left(root->right,ans);
    }
}
void leaf(TreeNode<int>* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }
    if(root->left)
    leaf(root->left,ans);
    if(root->right)
    leaf(root->right,ans);
}
void right(TreeNode<int>* root,vector<int>&v){
    if(root==NULL){
        return;
    }
    if(!root->left && !root->right){
        return;
    }
    v.push_back(root->data);
    if(root->right){
        right(root->right,v);
    }
    else if(root->left){
        right(root->left,v);
    }
    else{
        return;
    }
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>ans;
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return ans;
    }
    vector<int>v;
    ans.push_back(root->data);
    if(root->left)
    left(root->left,ans);
    leaf(root,ans);
    if(root->right)
    right(root->right,v);
    reverse(v.begin(),v.end());
    if(!v.empty()){
        for (auto i : v) {
        ans.push_back(i);
        }
    }
    return ans;
}
