#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    map<int,int> mp;
    if(!root)return {};
    queue<pair<TreeNode<int>*,int>> qt;
    qt.push({root,0});
    while(qt.size()){
        pair<TreeNode<int>*,int> ft=qt.front();
        qt.pop();
        int idx=ft.second;
        if(mp.find(idx)==mp.end())mp[idx]=ft.first->val;
        if(ft.first->left){
            qt.push({ft.first->left,idx-1});
        }
        if(ft.first->right){
            qt.push({ft.first->right,idx+1});
        }
    }
    vector<int> ans;
    for(auto it:mp)ans.push_back(it.second);
    return ans;
}
