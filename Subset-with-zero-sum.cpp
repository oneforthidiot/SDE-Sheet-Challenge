#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
    unordered_map<int,int> mp;
    int n=arr.size();
    mp[0]=-1;
    int ans=0;
    int curr=0;
    for(int i=0;i<n;i++){
        curr+=arr[i];
        if(curr==0){
          ans=max(ans,i+1);
        }
        if(mp.find(curr)!=mp.end()){
           ans=max(ans,i-mp[curr]);
        }
        else{
          mp[curr]=i;
        }
    }
    return ans;
}
