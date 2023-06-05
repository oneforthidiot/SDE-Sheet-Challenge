#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    int n=arr.size();
    unordered_map<int,int> mp;
    // mp[0]++;
    int curr=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        curr^=arr[i];
        if(curr==x)cnt++;
        if(mp.find(curr^x)!=mp.end()){
            cnt+=mp[curr^x];
        }
        mp[curr]++;
    }
    return cnt;
}
