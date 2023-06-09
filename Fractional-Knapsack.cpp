#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w){
    priority_queue<pair<double,int>> pq;
    for(int i=0;i<n;i++){
        double temp=double(items[i].second)/double(items[i].first);
        pq.push({temp,i});
    }
    double ans=0;
    while(w>0 and pq.size()){
        pair<double,int> ft=pq.top();
        pq.pop();
        int temp=min(w,items[ft.second].first);
        w-=temp;
        double t=ft.first*temp;
        ans+=t;
    }
    return ans;
}
