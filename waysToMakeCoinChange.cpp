#include<bits/stdc++.h>
long long rec(int *denominations,int n,int idx,int value,vector<vector<long long>> &dp){
    if(idx>=n){
        return value==0;
    }
    if(dp[idx][value]!=-1)return dp[idx][value];
    if(denominations[idx]<=value){
        long long a=rec(denominations,n,idx+1,value,dp);
        long long b=rec(denominations,n,idx,value-denominations[idx],dp);
        return dp[idx][value]=a+b;
    }
    else{
        return dp[idx][value]=rec(denominations,n,idx+1,value,dp);
    }
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long long>> dp(n+1,vector<long long>(value+1,-1));
    long long ans=rec(denominations,n,0,value,dp);
    return ans;
}
