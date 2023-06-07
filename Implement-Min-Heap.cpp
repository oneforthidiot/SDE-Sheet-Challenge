#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    multiset<int> mst;
    vector<int> ans;
    for(auto it:q){
        if(it.size()==1){
            ans.push_back(*mst.begin());
            mst.erase(mst.begin());
        }
        else{
            mst.insert(it[1]);
        }
    }
    return ans;
}
