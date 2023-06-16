#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
   vector<int> ans;
   queue<BinaryTreeNode<int>*> qt;
   if(!root)return ans;
   qt.push(root);
   while(qt.size()){
       auto ft=qt.front();
       qt.pop();
       ans.push_back(ft->val);
       if(ft->left)qt.push(ft->left);
       if(ft->right)qt.push(ft->right);
   }
   return ans;
}
