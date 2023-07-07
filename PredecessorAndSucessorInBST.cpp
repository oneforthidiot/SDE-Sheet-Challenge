#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void pre(BinaryTreeNode<int> * root,int key,int &p){
    if(root->data<=key){
        if(root->right)pre(root->right,key,p);
    }
    else{
        p=root->data;
        if(root->left)pre(root->left,key,p);
    }
}
void suc(BinaryTreeNode<int> * root,int key,int &s){
    if(root->data>=key){
        if(root->left)pre(root->left,key,s);
    }
    else{
        s=root->data;
        if(root->right)pre(root->right,key,s);
    }
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int s=-1,p=-1;
    BinaryTreeNode<int> *temp=root;
    while(temp and temp->data!=key){
        if(temp->data>key){
            s=temp->data;
            temp=temp->left;
        }
        else{
            p=temp->data;
            temp=temp->right;
        }
    }
    BinaryTreeNode<int> *l=temp->left;
    while(l){
        p=l->data;
        l=l->right;
    }
    BinaryTreeNode<int> *r=temp->right;
    while(r){
        s=r->data;
        r=r->left;
    }
    return {p,s};
}
