#include<bits/stdc++.h>
int rec(string &str1,string &str2,int i,int j,vector<vector<int>> &dp){
    if(i==0)return j;
    if(j==0)return i;
    if(dp[i][j]!=-1)return dp[i][j];
    if(str1[i-1]==str2[j-1]){
        return dp[i][j]=rec(str1,str2,i-1,j-1,dp);
    }
    else return dp[i][j]=1+min({rec(str1,str2,i-1,j,dp),rec(str1,str2,i,j-1,dp),rec(str1,str2,i-1,j-1,dp)});
}
int editDistance(string str1, string str2){
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans=rec(str1,str2,n,m,dp);
    return ans;
}
