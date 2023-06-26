#include<bits/stdc++.h>
int rec(string &s,string &t,int n,int m,vector<vector<int>> &dp){
	if(n==0 or m==0)return 0;
	if(dp[n][m]!=-1)return dp[n][m];
	if(s[n-1]==t[m-1]){
		return dp[n][m]=1+rec(s,t,n-1,m-1,dp);
	}
	return dp[n][m]=max(rec(s,t,n-1,m,dp),rec(s,t,n,m-1,dp));
}
int lcs(string s, string t){
	int n=s.size();
	int m=t.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
	return rec(s,t,n,m,dp);
}
