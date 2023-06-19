#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long solve(TreeNode<int> *root,long long &res){
    if(!root)return 0;
    int l=solve(root->left,res);
    int r=solve(root->right,res);
    int temp=max(l,r)+root->val;
    if(!root->left and !root->right){
        temp=max(temp,root->val);
    }
    long long ans=max(l*1ll+r*1ll+root->val*1ll,temp*1ll);
    res=max(ans,res);
    return temp;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    if(!root or !root->left or !root->right)return -1;
    long long ans=0;
    solve(root,ans);
    return ans;
}
