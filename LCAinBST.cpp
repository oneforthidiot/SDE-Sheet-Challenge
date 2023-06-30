#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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
TreeNode<int>* rec(TreeNode<int>* root,int x,int y){
    if(!root)return root;
    if(root->data==x or root->data==y)return root;
    TreeNode<int>* l=rec(root->left,x,y);
    TreeNode<int>* r=rec(root->right,x,y);
    if(l and r)return root;
    if(!l)return r;
    if(!r)return l;
}
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q){
	return rec(root,P->data,Q->data);
}
