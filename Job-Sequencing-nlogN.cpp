#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs){
    auto cmp=[](vector<int> &a,vector<int> &b){
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]<b[0];
    };
    sort(jobs.begin(),jobs.end());
    multiset<int> mst;
    int n=jobs.size();
    int ans=0;
    for(int i=n-1;i>=0;i--){
        int slot=0;
        if(i==0){
            slot=jobs[i][0];
        }
        else{
            slot=jobs[i][0]-jobs[i-1][0];

        }
        mst.insert(jobs[i][1]);
        while(slot and mst.size()){
            auto it=mst.end();
            --it;
            ans+=*it;
            mst.erase(it);
            slot--;

        }
    }
    return ans;
}
