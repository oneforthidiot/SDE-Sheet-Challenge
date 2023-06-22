/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* helper(vector<int> &post,vector<int> &in,int &idx,int l,int r){
     // if(idx<0)return NULL;
     if(l==r){
          TreeNode<int> * root=new TreeNode<int>(post[idx]);
          idx--;
          return root;
     }
     if(l>r)return NULL;
     TreeNode<int> * root=new TreeNode<int>(post[idx]);
     int num=post[idx];
     idx--;
     int idx1=0;
     for(int i=l;i<=r;i++){
          if(in[i]==num){
               idx1=i;
               break;
          }
     }
     root->right=helper(post,in,idx,idx1+1,r);
     root->left=helper(post,in,idx,l,idx1-1);
     
     return root;

}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	int idx=inOrder.size()-1;
     return helper(postOrder,inOrder,idx,0,idx);
}
