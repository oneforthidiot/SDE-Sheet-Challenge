#include <bits/stdc++.h> 
int rec(vector<int> &arr,int idx,int prev,vector<vector<int>> &dp){
	if(idx==arr.size())return 0;
	if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
	int temp=(prev==-1)?INT_MIN:arr[prev];
	if(arr[idx]>temp){
		int a=arr[idx]+rec(arr,idx+1,idx,dp);
		int b=rec(arr,idx+1,prev,dp);
		return dp[idx][prev+1]=max(a,b);
	}
	else return dp[idx][prev+1]=rec(arr,idx+1,prev,dp);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n){
	vector<vector<int>> dp(n+10,vector<int>(n+10,-1));
	int ans=rec(rack,0,-1,dp);
	return ans;
}
