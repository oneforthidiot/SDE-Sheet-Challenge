#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr){
    map<int,int> mp;
    for(auto it:arr){
        mp[it]++;
    }
    vector<pair<int,int>> pr;
    for(auto it:mp){
        pr.push_back({it.second,it.first});
    }
    sort(pr.begin(),pr.end());
    vector<int> ans;
    while(pr.size() and k--){
        ans.push_back(pr.back().second);
        pr.pop_back();
    }
    sort(ans.begin(),ans.end());
    return ans;
}
