#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> pr;
    for(int i=0;i<start.size();i++){
        pr.push_back({finish[i],start[i]});
    }
    sort(pr.begin(),pr.end());
    int c=1;
    int prev=pr[0].first;
    for(int i=1;i<pr.size();i++){
        if(pr[i].second>=prev){
            prev=pr[i].first;
            c++;
        }
    }
    return c;
}
