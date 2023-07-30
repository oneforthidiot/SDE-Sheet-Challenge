const int X=5e3+1;
vector<int> gh[X];
int vis[X];
bool isCycle(int node,int prev){
    vis[node]=1;
    for(auto it:gh[node]){
        if(!vis[it]){
           if(isCycle(it,node))return true;
        }
        else{
            if(prev!=it)return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    for(int i=0;i<=n;i++){
        gh[i].clear();
        vis[i]=0;
    }
    for(auto it:edges){
        gh[it[0]].push_back(it[1]);
        gh[it[1]].push_back(it[0]);
    }
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            flag|=isCycle(i,-1);
        }
    }
    return ((flag)?"Yes":"No");


}
