#include<bits/stdc++.h>
bool helper(vector<vector<int>> &matrix,int mid){
    int count=0;
    int n=matrix.size();
    int m=matrix[0].size();
    int sz=(m*n+1)/2;
    for(auto it:matrix){
        count+=(upper_bound(it.begin(),it.end(),mid)-it.begin());
    }
    return count<sz;
}
int getMedian(vector<vector<int>> &matrix){
    int mn=INT_MAX;
    int mx=INT_MIN;
    for(auto it:matrix){
        mn=min(mn,it[0]);
        mx=max(mx,it.back());
    }
    int l=mn,r=mx;
    while(l<r){
        int mid=(l+r)/2;
        if(helper(matrix,mid)){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    return l;
}
