#include<bits/stdc++.h>
vector<vector<int>> mn_ans;
void rec(vector<int> &arr,int i,vector<int> &temp,int k){
	if(k==0){
		mn_ans.push_back(temp);
		return;
	}
	for(int idx=i;idx<arr.size();idx++){
		if(idx>i and arr[idx]==arr[idx-1])continue;
		temp.push_back(arr[idx]);
		// k-=arr[idx];
		rec(arr,idx+1,temp,k-arr[idx]);
		// k+=arr[idx];
		temp.pop_back();
		// rec(arr,idx+1,temp,k);
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	int sz=(1<<n);
	sort(arr.begin(),arr.end());
	mn_ans.clear();
	vector<int> temp;
	rec(arr,0,temp,target);
	return mn_ans;
}
