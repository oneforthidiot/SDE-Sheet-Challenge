#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k){
    // deque<int> qt(k);
    // vector<int> ans;
    // for(int i=0;i<k;i++){
    //     while(qt.size() and nums[qt.back()]<=nums[i]){
    //         qt.pop_back();
    //     }
    //     qt.push_back(i);
    // }
    // int n=nums.size();
    // for(int i=k;i<n;i++){
    //     ans.push_back(nums[qt.front()]);
    //     while(qt.size() and qt.back()<=i-k){
    //         qt.pop_back();
    //     }
    //     while(qt.size() and nums[qt.back()]<=nums[i]){
    //         qt.pop_back();
    //     }
    //     qt.push_back(i);
    // }
    // ans.push_back(nums[qt.front()]);
    // return ans;
    vector<int> ans;
        list<int> l;
        int i=0, j=0;
        while(j<nums.size()){
            while(!l.empty() && l.back()<nums[j])
                l.pop_back();
            l.push_back(nums[j]);
            if(j-i+1<k)j++;
            else 
            if(j-i+1==k){
                ans.push_back(l.front());
                if(l.front()==nums[i])
                l.pop_front();
                 i++;
                 j++;
            }
     }
     return ans;
}
