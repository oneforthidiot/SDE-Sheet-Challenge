#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    const int mx=1e9;
    vector<int> dist(n+1,mx);
    dist[src]=0;
    for(int i=1;i<n;i++){
        bool flag=false;
        for(auto &it:edges){
            if(dist[it[0]]!=mx and dist[it[1]]>dist[it[0]]+it[2]){
                dist[it[1]]=dist[it[0]]+it[2];
                flag=true;
            }
        }
        if(!flag)return dist[dest];
    }
    bool ok=false;
    for(auto it:edges){
        if(dist[it[1]]>dist[it[0]]+it[2]){
            dist[it[1]]=dist[it[0]]+it[2];
            ok=true;
        }
    }
    if(ok)return INT_MIN;
    return dist[dest];
}
