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

class BSTiterator
{
    public:
    stack<TreeNode<int>*> st;
    BSTiterator(TreeNode<int> *root)
    {
        TreeNode<int> *curr=root;
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
    }

    int next(){
        TreeNode<int> * curr=st.top();
        st.pop();
        TreeNode<int>* r=curr->right;
        while(r){
            st.push(r);
            r=r->left;
        }
        return curr->data;
    }

    bool hasNext()
    {
        return st.size();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
