#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* solver(vector<int> &inorder, vector<int> &preorder, unordered_map<int, int> &hash, int &index, int start, int end){
    if(start == end){
        TreeNode<int>* root;
        root = new TreeNode<int>(preorder[index]);
        index++;
        return root;
    }
    if(start > end || end < 0) return NULL;
    TreeNode<int>* root;
    root = new TreeNode<int>(preorder[index]);
    int mid = hash[preorder[index]];
    index++;
    root->left = solver(inorder, preorder, hash, index, start, mid-1);
    root->right = solver(inorder, preorder, hash, index, mid + 1, end);
    return root;
} 


TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder){
	
    int n = preorder.size();
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++){
        hash[inorder[i]] = i;
    }
    int index = 0;
    return solver(inorder, preorder, hash, index, 0, n-1); 
}
// TreeNode<int> *helper(vector<int> &inorder,vector<int> &preorder,int &idx,int l,int r){
//     if(l>r or r<0)return NULL;
//     TreeNode<int>* root=new TreeNode<int>(preorder[idx]);
//     if(l==r)return root;
//     int num=preorder[idx];
//     idx++;
//     int mid=0;
//     for(int i=l;i<=r;i++){
//         if(inorder[i]==num){
//             mid=i;
//             break;
//         }
//     }
//     root->left=helper(inorder,preorder,idx,l,mid-1);
//     root->right=helper(inorder,preorder,idx,mid+1,r);
//     return root;
// }
// TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder){
//     int idx=0;
// 	return helper(inorder,preorder,idx,0,preorder.size()-1);
// }
