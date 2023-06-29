#include <bits/stdc++.h> 
bool rec(vector<int> &arr,int idx,int k,vector<vector<int>> &dp){
    if(idx==arr.size()){
        return k==0;
    }
    if(dp[idx][k]!=-1)return dp[idx][k];
    if(arr[idx]<=k){
        bool f1=rec(arr,idx+1,k-arr[idx],dp);
        bool f2=rec(arr,idx+1,k,dp);
        return dp[idx][k]=(f1 or f2);
    }
    else{
        return dp[idx][k]=rec(arr,idx+1,k,dp);
    }
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    bool ans=rec(arr,0,k,dp);
    return ans;
}
