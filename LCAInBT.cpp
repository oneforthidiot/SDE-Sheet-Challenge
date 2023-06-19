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
vector<int> temp;
void path(TreeNode<int> *root,int x,vector<int> &t){
    if(!root)return;
    if(root->data==x){
        t.push_back(root->data);
        temp=t;
        return;
    }
    t.push_back(root->data);
    path(root->left,x,t);
    path(root->right,x,t);
    t.pop_back();
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y){
	vector<int> t;
    vector<int> path1,path2;
    path(root,x,t);
    path1=temp;
    temp.clear();
    t.clear();
    path(root,y,t);
    path2=temp;
    int prev=-1;
    for(int i=0;i<min(path1.size(),path2.size());i++){
        if(path1[i]!=path2[i]){
            break;
        }
        prev=path1[i];
    }
    return prev;
}
