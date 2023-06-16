#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void rec(TreeNode* root,vector<int> &temp){
    if(!root)return;
    temp.push_back(root->data);
    rec(root->left,temp);
    rec(root->right,temp);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> temp;
    rec(root,temp);
    return temp;
}
