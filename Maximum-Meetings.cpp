#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<pair<int,int>> pr;
    int n=start.size();
    for(int i=0;i<n;i++){
        pr.push_back({end[i],i});
    }
    sort(pr.begin(),pr.end());
    int prev=pr[0].first;
    vector<int> ans;
    ans.push_back(pr[0].second+1);
    for(int i=1;i<n;i++){
        if(start[pr[i].second]>prev){
            ans.push_back(pr[i].second+1);
            prev=pr[i].first;
        }
    }
    return ans;

    
}
