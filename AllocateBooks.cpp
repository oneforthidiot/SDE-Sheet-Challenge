#include <bits/stdc++.h> 
bool helper(vector<int> time,long long mid,int m){
	int count=1;
	long long curr=time[0];
	for(int i=1;i<time.size();i++){
		if(curr+time[i]>mid){
			curr=time[i];
			count++;
		}
		else{
			curr+=time[i];
		}
	}
	return count<=m;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) {	
	long long l=*max_element(time.begin(),time.end());
	long long r=accumulate(time.begin(),time.end(),0*1ll);
	long long ans=INT64_MAX;
	if(n>=m){
		return l;
	}
	while(l<=r){
		long long mid=(l+r)/2;
		if(helper(time,mid,n)){
			ans=min(ans,mid);
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}
