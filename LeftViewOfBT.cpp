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

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    queue<TreeNode<int>*> qt;
    if(!root)return ans;
    qt.push(root);
    while(qt.size()){
        int sz=qt.size();
        for(int i=0;i<sz;i++){
            TreeNode<int> *ft=qt.front();
            qt.pop();
            if(i==0){
                ans.push_back(ft->data);
            }
            if(ft->left)qt.push(ft->left);
            if(ft->right)qt.push(ft->right);
        }
    }
    return ans;
}
