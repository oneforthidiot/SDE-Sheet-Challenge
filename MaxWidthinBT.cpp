#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

int getMaxWidth(TreeNode<int> *root){
    queue<pair<TreeNode<int>*,int>> qt;
    if(!root)return 0;
    qt.push({root,1});
    int ans=0;
    while(qt.size()){
        int sz=qt.size();
        int start=qt.front().second;
        int end=0;
        ans=max(ans,sz);
        for(int i=0;i<sz;i++){
            pair<TreeNode<int>*,int> ft=qt.front();
            qt.pop();
            int idx=ft.second;
            if(i==sz-1){
                end=ft.second;
            }
            if(ft.first->left){
                qt.push({ft.first->left,2*idx-1});
            }
            if(ft.first->right){
                qt.push({ft.first->right,2*idx});
            }
        }
        // ans=max(ans,end-start+1);
    }
    return ans;
}
