#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<int> dis(vertices,INT_MAX);
    vector<pair<int,int>> gh[vertices+1];
    for(auto &it:vec){
        gh[it[0]].push_back({it[1],it[2]});
        gh[it[1]].push_back({it[0],it[2]});
    }
    multiset<pair<int,int>> mst;
    mst.insert({0,source});
    dis[source]=0;
    while(mst.size()){
        pair<int,int> ft=*mst.begin();
        mst.erase(mst.begin());
        int node=ft.second;
        int d0=ft.first;
        for(auto &it:gh[node]){
            int x=it.first;
            int d=it.second;
            if(dis[node]+d<dis[x]){
                dis[x]=dis[node]+d;
                mst.insert({dis[x],x});
            }
        }
    }
    return dis;

}
