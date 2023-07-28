#include<bits/stdc++.h>
const int X=400;
vector<int> gh[X];
int color[X];
int vis[X];
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n=edges.size();
	memset(color,-1,sizeof(color));
	for(int i=0;i<=n;i++)gh[i].clear();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(edges[i][j]){
				gh[i].push_back(j);
				gh[j].push_back(i);
			}
		}
	}
	queue<int> qt;
	for(int i=0;i<n;i++){
		if(color[i]!=-1)continue;
		color[i]=1;
		qt.push(i);
		while(qt.size()){
			int ft=qt.front();
			qt.pop();
			for(auto it:gh[ft]){
				if(color[it]==-1){
					if(color[ft]==1)color[it]=0;
					else color[it]=1;
					qt.push(it);
				}
				else{
					if(color[ft]==color[it])return false;
				}
			}
		}
	}
	return true;
}
