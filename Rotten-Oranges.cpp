#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m){
    queue<pair<int,int>> qt;
    vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                qt.push({i,j});
            }
            if(grid[i][j]==1){
                cnt++;
            }
        }
    }
    int level=0;
    if(cnt==0)return 0;
    while(qt.size()){
        int sz=qt.size();
        while(sz--){
            pair<int,int> ft=qt.front();
            qt.pop();
            for(auto &it:dir){
                int x=ft.first+it.first;
                int y=ft.second+it.second;
                if(x<0 or y<0 or x>=n or y>=m or grid[x][y]!=1)continue;
                cnt--;
                grid[x][y]=2;
                qt.push({x,y});
            }
        }
        level++;
    }
    if(cnt>0)return -1;
    return level-1;
}
