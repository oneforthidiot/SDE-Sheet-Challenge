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
TreeNode<int>* helper(vector<int> &arr,int l,int r){
    if(l>r)return NULL;
    int mid=(l+r)/2;
    TreeNode<int>* root=new TreeNode<int>(arr[mid]);
    root->left=helper(arr,l,mid-1);
    root->right=helper(arr,mid+1,r);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return helper(arr,0,n-1);
}
