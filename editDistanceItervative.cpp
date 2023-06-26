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
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
        }
    }
    int ans=dp[n][m];//rec(str1,str2,n,m,dp);
    return ans;
}
