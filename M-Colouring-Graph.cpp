#include <bits/stdc++.h> 
const int X=100;
vector<int> gh[X];
int color[X];
bool isValid(vector<vector<int>> &grid,int node,int c,int n){
    for(int i=0;i<n;i++){
        if(grid[node][i]==1 and color[i]==c)return false;
    }
    return true;
}
bool help(vector<vector<int>> &grid,int node,int m,int n){
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isValid(grid,node,i,n)){
            color[node]=i;
            if(help(grid,node+1,m,n))return true;
            color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    for(int i=0;i<100;i++){
        gh[i].clear();
        color[i]=0;
    }
    int n=mat.size();
    if(help(mat,0,m,n))return "YES";
    return "NO";

}
