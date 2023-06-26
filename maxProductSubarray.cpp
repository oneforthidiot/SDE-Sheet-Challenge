#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n){
	vector<int> mn(n+1),mx(n+1);
	mn[0]=arr[0];
	mx[0]=arr[0];
	int ans=arr[0];
	for(int i=1;i<n;i++){
		mx[i]=max({mn[i-1]*arr[i],mx[i-1]*arr[i],arr[i]});
		mn[i]=min({mn[i-1]*arr[i],mx[i-1]*arr[i],arr[i]});
		ans=max(ans,mx[i]);
	}
	return ans;
}
