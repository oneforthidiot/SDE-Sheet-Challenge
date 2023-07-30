#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> gh[v+1];
    vector<int> indegree(v+1,0);
    for(auto it:edges){
        gh[it[0]].push_back(it[1]);
        indegree[it[1]]++;
    }
    queue<int> qt;
    vector<int> ans;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            qt.push(i);
            indegree[i]--;
            ans.push_back(i);
        }
    }
    while(qt.size()){
        int ft=qt.front();
        qt.pop();
        for(auto it:gh[ft]){
            indegree[it]--;
            if(indegree[it]==0){
                qt.push(it);
                ans.push_back(it);
            }
        }
    }
    return ans;
}
