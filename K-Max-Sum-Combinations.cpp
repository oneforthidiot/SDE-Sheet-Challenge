#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	multiset<pair<int,pair<int,int>>> mst;
	mst.insert({a[n-1]+b[n-1],{n-1,n-1}});
	vector<int> ans;
	set<pair<int,int>> st;
	st.insert({n-1,n-1});
	while(mst.size() and ans.size()<k){
		auto it=mst.end();
		--it;
		pair<int,pair<int,int>> ft=*it;
		mst.erase(it);
		ans.push_back(ft.first);
		int i=ft.second.first;
		int j=ft.second.second;
		if(i>0 and st.find({i-1,j})==st.end()){
			mst.insert({a[i-1]+b[j],{i-1,j}});
			st.insert({i-1,j});
		}
		if(j>0 and st.find({i,j-1})==st.end()){
			mst.insert({a[i]+b[j-1],{i,j-1}});
			st.insert({i,j-1});
		}
	}
	return ans;
	
}
