#include<bits/stdc++.h>
int cutRod(vector<int> &price, int n){
	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i<=j){
				dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i][j-i]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][n];
}
