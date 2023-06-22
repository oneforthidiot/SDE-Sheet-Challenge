#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    deque<BinaryTreeNode<int>*> qt;
    qt.push_back(root);
    if(!root)return;
    while(qt.size()){
        int sz=qt.size();
        BinaryTreeNode<int> * prev=NULL;
        for(int i=0;i<sz;i++){
            BinaryTreeNode<int>* ft=qt.back();
            qt.pop_back();
            if(!prev){
                prev=ft;
            }
            else{
                ft->next=prev;
                prev=ft;
            }
            if(ft->right)qt.push_front(ft->right);
            if(ft->left)qt.push_front(ft->left);
        }
    }
}
