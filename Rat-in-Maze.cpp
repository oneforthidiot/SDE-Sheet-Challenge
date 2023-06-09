#include <bits/stdc++.h> 
int vis[11][11];
vector<vector<int>> ans;
vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
bool isValid(vector<vector<int>> &maze,int i,int j){
    if(i<0 or j<0 or i>=maze.size() or j>=maze[0].size() or !maze[i][j])return false;
    return true;
}
void rec(vector<vector<int>> &maze,int i,int j,vector<int>&temp){
    int n=maze.size();
    if(i==n-1 and j==n-1){
      vector<int> t;
      for(int ii=0;ii<n;ii++){
        for(int jj=0;jj<n;jj++){
            t.push_back(vis[ii][jj]);
        }
      }
      ans.push_back(t);
      return;
    }
    for(auto &it:dir){
      int x=it.first+i;
      int y=it.second+j;
      if(!isValid(maze,x,y) or vis[x][y])continue;
      temp[(x+1)*(y+1)-1]=1;
      vis[x][y]=1;
      rec(maze,x,y,temp);
      temp[2*x+y]=0;
      vis[x][y]=0;
    }
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<int> temp(n*n,0);
    ans.clear();
    memset(vis,0,sizeof(vis));
    vis[0][0]=1;
    // vis[n-1][n-1]=1;
    if(maze[0][0]!=1 or maze[n-1][n-1]!=1)return ans;
    temp[0]=1;
    temp[n*n-1]=1;
    rec(maze,0,0,temp);
    return ans;

}
