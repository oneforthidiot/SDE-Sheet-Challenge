#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root){
        map<int,vector<int>> mp;
        queue<pair<TreeNode<int>*,int>> qt;
        qt.push({root,0});
        while(qt.size()){
            pair<TreeNode<int>*,int> ft=qt.front();
            qt.pop();
            int idx=ft.second;
            mp[idx].push_back(ft.first->data);
            if(ft.first->left){
                qt.push({ft.first->left,idx-1});
            }
            if(ft.first->right){
                qt.push({ft.first->right,idx+1});
            }
        }
        vector<int> ans;
        for(auto it:mp){
            for(auto i:it.second){
                ans.push_back(i);
            }
        }
        return ans;
}
