#include <bits/stdc++.h> 
int dp[101][101];
bool isPal(string &str,int l,int r){
    while(l<r){
        if(str[l]!=str[r])return 0;
        l++;
        r--;
    }
    return 1;
}
int rec(string &str,int l,int r){
    if(l>=r)return 0;
    if(isPal(str,l,r))return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int ans=1e7;
    for(int i=l;i<r;i++){
        int temp=1+rec(str,l,i)+rec(str,i+1,r);
        ans=min(ans,temp);
    }
    return dp[l][r]=ans;
}
int palindromePartitioning(string str) {
    memset(dp,-1,sizeof(dp));
    unordered_map<string,int> mp;
    int ans=rec(str,0,str.size()-1);
    return ans;
}
