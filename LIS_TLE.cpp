#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n){
   vector<int> dp(n+1);
   for(int i=0;i<n;i++){
       dp[i]=1;
       for(int j=i-1;j>=0;j--){
           if(arr[j]<arr[i] and dp[i]<dp[j]+1){
               dp[i]=max(dp[i],dp[j]+1);
           }
       }
   }
   return *max_element(dp.begin(),dp.end());
}
