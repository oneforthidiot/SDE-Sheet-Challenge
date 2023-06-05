#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	sort(arr.begin(),arr.end());
    set<vector<int>> ans;
    for(int i=0;i<n-1;i++){
        int l=i+1,r=n-1;
        while(l<r){
            int temp=arr[i]+arr[l]+arr[r];
            if(temp==K){
                if(arr[l]==arr[r]){
                    int sz=(r-l+1);
                    int t=(sz*(sz-1))/2;
                    while(t--){
                        ans.insert({arr[i],arr[l],arr[r]});
                    }
                    break;
                }
                else{
                    int l1=l+1;
                    int r1=r-1;
                    int c1=1,c2=1;
                    while(arr[l1]==arr[l]){
                        c1++;
                        l1++;
                    }
                    while(arr[r1]==arr[r]){
                        r1--;
                        c2++;
                    }
                    int sz=c1*c2;
                    while(sz--){
                        ans.insert({arr[i],arr[l],arr[r]});
                    }
                    l=l1;
                    r=r1;
                }
            }
            else
            if(temp>K){
                r--;
            }
            else{
                l++;
            }
        }
    }
    vector<vector<int>> ans1;
    for(auto it:ans)ans1.push_back(it);
    return ans1;
}
