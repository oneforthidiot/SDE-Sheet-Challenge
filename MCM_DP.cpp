#include <bits/stdc++.h> 
int rec(vector<int>&arr,int l,int r,vector<vector<int>> &dp){
    if(l==r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int ans=INT_MAX;
    for(int i=l;i<r;i++){
        int temp=arr[l-1]*arr[i]*arr[r]+rec(arr,l,i,dp)+rec(arr,i+1,r,dp);
        ans=min(ans,temp);
    } 
    return dp[l][r]=ans;
}
int matrixMultiplication(vector<int> &arr, int N){
    vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
    int ans=rec(arr,1,N-1,dp);
    return ans;
}
