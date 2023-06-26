#include<bits/stdc++.h>
int rec(vector<int> &val,vector<int> &wt,int idx,int w,vector<vector<int>> &dp){
	if(idx>=val.size())return 0;
	if(dp[idx][w]!=-1)return dp[idx][w];
	if(wt[idx]<=w){
		return dp[idx][w]=max(rec(val,wt,idx+1,w,dp),val[idx]+rec(val,wt,idx+1,w-wt[idx],dp));
	}
	else return dp[idx][w]=rec(val,wt,idx+1,w,dp);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){
	vector<vector<int>> dp(n+1,vector<int>(w+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=w;j++){
			if(weights[i-1]<=j){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-weights[i-1]]+values[i-1]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	int ans=dp[n][w];//rec(values,weights,0,w,dp);
	return ans;
}
