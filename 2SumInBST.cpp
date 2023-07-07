#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    stack<BinaryTreeNode<int>*> st1,st2;
    BinaryTreeNode<int> * curr=root;
    while(curr){
        st1.push(curr);
        curr=curr->left;
    } 
    while(root){
        st2.push(root);
        root=root->right;
    }
    while(st1.top()!=st2.top()){
        if((st1.top())->data+(st2.top())->data==k){
            return true;
        }
        if(st1.top()->data+st2.top()->data>k){
            BinaryTreeNode<int> *curr=st2.top()->left;
            st2.pop();
            while(curr){
                st2.push(curr);
                curr=curr->right;
            }
        }
        else{
            BinaryTreeNode<int> *curr=st1.top()->right;
            st1.pop();
            while(curr){
                st1.push(curr);
                curr=curr->left;
            }
        }
    }
    return false;
}
