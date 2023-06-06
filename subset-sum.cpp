#include <bits/stdc++.h> 
vector<int> subsetSum(vector<int> &num){
    int n=num.size();
    int sz=(1<<n);
    vector<int> ans;
    for(int i=0;i<sz;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                sum+=num[j];
            }
        }
        ans.push_back(sum);
    }
    sort(ans.begin(),ans.end());
    return ans;
    // Write your code here.
}
