#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v){
    int n=v.size();
    int sz=(1<<n);
    vector<vector<int>> ans;
    for(int i=0;i<sz;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                temp.push_back(v[j]);
            }
        }
        ans.push_back(temp);
    }    
    return ans;
}
