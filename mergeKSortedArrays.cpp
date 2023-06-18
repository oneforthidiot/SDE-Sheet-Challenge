#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    vector<int> ans;
    multiset<pair<int,pair<int,int>>> mst;
    for(int i=0;i<k;i++){
        mst.insert({kArrays[i][0],{0,i}});
    }
    while(mst.size()){
        auto ft=*mst.begin();
        int num=ft.first;
        ans.push_back(num);
        int i=ft.second.first;
        int j=ft.second.second;
        mst.erase(mst.begin());
        if(i<kArrays[j].size()-1){
            mst.insert({kArrays[j][++i],{i,j}});
        }
    }
    return ans;
}
