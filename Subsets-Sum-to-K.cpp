#include<bits/stdc++.h>
vector<vector<int>> ans;
void rec(vector<int> &arr,int i,vector<int> &temp,int sum){
    if(i==arr.size()){
        if(sum==0){
            ans.push_back(temp);
        }
        return;
    }
    temp.push_back(arr[i]);
    sum-=arr[i];
    rec(arr,i+1,temp,sum);
    sum+=arr[i];
    temp.pop_back();
    rec(arr,i+1,temp,sum);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k){
    // int sz=(1<<n);
    // set<vector<int>> ans;
    // for(int i=0;i<sz;i++){
    //     vector<int> temp;
    //     int sum=0;
    //     for(int j=0;j<n;j++){
    //         if(i&(1<<j)){
    //             sum+=arr[j];
    //             temp.push_back(arr[j]);
    //         }
    //     }
    //     if(temp.size()==0)continue;
    //     if(sum==k and temp.size()){
    //         sort(temp.begin(),temp.end());
    //         ans.insert(temp);
    //     }
    // }
    // if(k==0)ans.insert({});
    // vector<vector<int>> ans1;
    // for(auto it:ans)ans1.push_back(it);
    // return ans1;
    ans.clear();
    vector<int> temp;
    rec(arr,0,temp,k);
    return ans;
}
