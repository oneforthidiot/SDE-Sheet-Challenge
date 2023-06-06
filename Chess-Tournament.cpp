#include <bits/stdc++.h> 
bool helper(vector<int> postitions,int mid,int m){
	int c=1;
	int curr=postitions[0];
	for(int i=0;i<postitions.size();i++){
		if(postitions[i]-curr>=mid){
			c++;
			curr=postitions[i];
		}
		if(c==m)return true;
	}
	return c>=m;
}
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(),positions.end());
	int l=1,r=1e9;
	while(l<=r){
		int mid=(l+r)/2;
		if(helper(positions,mid,c)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return r;
}
