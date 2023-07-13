#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
vector<int> rec(TreeNode<int>* root){
    if(!root)return {INT_MAX,INT_MIN,0};
    if(!root->left and !root->right)return {root->data, root->data, 1};
    vector<int> lt=rec(root->left);
    vector<int> rt=rec(root->right);
    vector<int> ret(3,0);
    if(root->data<rt[0] and root->data>lt[1]){
        ret[0]=min({root->data,lt[0],rt[0]});
        ret[1]=max({root->data,rt[1],lt[1]});
        ret[2]=1+rt[2]+lt[2];
        return ret;
    }
    ret[0]=INT_MIN;
    ret[1]=INT_MAX;
    ret[2]=max(lt[2],rt[2]);
    return ret;

}
int largestBST(TreeNode<int>* root) {
    vector<int> ans=rec(root);
    return ans[2];
}
