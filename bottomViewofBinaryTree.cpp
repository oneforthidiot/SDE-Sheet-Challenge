#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){
    map<int,int> mp;
    if(!root)return {};
    queue<pair<BinaryTreeNode<int>*,int>> qt;
    qt.push({root,0});
    while(qt.size()){
        pair<BinaryTreeNode<int>*,int> ft=qt.front();
        qt.pop();
        int idx=ft.second;
        mp[idx]=ft.first->data;
        if(ft.first->left){
            qt.push({ft.first->left,idx-1});
        }
        if(ft.first->right){
            qt.push({ft.first->right,idx+1});
        }
    }
    vector<int> ans;
    for(auto it:mp)ans.push_back(it.second);
    return ans;
}
