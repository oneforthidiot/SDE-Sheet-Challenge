#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/
vector<int> ans;
void rec(TreeNode<int> *root,int x,vector<int> &path){
	if(!root)return;
	if(root->data==x){
		ans=path;
		ans.push_back(root->data);
		return;
	}
	path.push_back(root->data);
	rec(root->left,x,path);
	rec(root->right,x,path);
	path.pop_back();
	
}

vector<int> pathInATree(TreeNode<int> *root, int x){
    vector<int> path;
	rec(root,x,path);
	return ans;
}
