#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr){
    int l1=INT_MAX;
    int l2=INT_MAX;
    int c1=0;
    int c2=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(c1==0 and l2!=arr[i]){
            l1=arr[i];
            c1=1;
        }
        else
        if(c2==0 and l1!=arr[i]){
            l2=arr[i];
            c2=1;
        }
        else
        if(arr[i]==l1)c1++;
        else
        if(arr[i]==l2)c2++;
        else{
            c1--;
            c2--;
        }
    }
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==l1)cnt1++;
        if(arr[i]==l2)cnt2++;
    }
    vector<int> ans;
    if(cnt1>n/3)ans.push_back(l1);
    if(cnt2>n/3)ans.push_back(l2);
    return ans;


}
