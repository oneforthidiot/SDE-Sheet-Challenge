#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k){
	multiset<int> mst1,mst2;
	for(auto it:arr){
		mst1.insert(it);
		mst2.insert(it);
		if(mst1.size()>k){
			auto it=mst1.end();
			--it;
			mst1.erase(it);
		}
		if(mst2.size()>k){
			mst2.erase(mst2.begin());
		}
	}
	vector<int> ans;
	auto it1=mst1.end();
	--it1;
	auto it2=mst2.begin();
	ans={*it1,*it2};
	return ans;

}
