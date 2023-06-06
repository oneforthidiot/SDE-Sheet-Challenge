#include <bits/stdc++.h> 
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr){
    set<vector<int>> ans;
    int sz=(1<<n);
    for(int i=0;i<sz;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                temp.push_back(arr[j]);
            }
        }
        sort(temp.begin(),temp.end());
        ans.insert(temp);
    }
    vector<vector<int>> ans1;
    for(auto it:ans)ans1.push_back(it);
    return ans1;
}
