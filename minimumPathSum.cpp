#include <bits/stdc++.h> 
int rec(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
    int n=grid.size();
    int m=grid[0].size();
    if(i<0 or j<0 or i>=n or j>=m)return INT_MAX;
    if(i==n-1 and j==m-1){
        return grid[i][j];
    }
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=grid[i][j]+min(rec(grid,i+1,j,dp),rec(grid,i,j+1,dp));
}
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans=rec(grid,0,0,dp);
    return ans;
}
