#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root){
    deque<BinaryTreeNode<int>*> dq;
    dq.push_back(root);
    if(!root)return {};
    vector<int> ans;
    bool flag=true;
    while(dq.size()){
        if(flag)flag=false;
        else flag=true;
        int sz=dq.size();
        while(sz--){
            if(flag){
                // flag=false;
                auto ft=dq.front();
                dq.pop_front();
                ans.push_back(ft->data);
                if(ft->right)dq.push_back(ft->right);
                if(ft->left)dq.push_back(ft->left);
                
            }
            else{
                // flag=true;
                auto ft=dq.back();
                dq.pop_back();
                ans.push_back(ft->data);
                if(ft->left)dq.push_front(ft->left);
                if(ft->right)dq.push_front(ft->right);
                
            }
        }
        
    }
    return ans;
}
