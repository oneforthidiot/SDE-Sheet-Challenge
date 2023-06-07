#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long ans=0;
    vector<long> pref(n+1);
    vector<long> suff(n+1);
    pref[0]=arr[0];
    suff[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        pref[i]=max(pref[i-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        suff[i]=max(suff[i+1],arr[i]);
    }
    for(int i=0;i<n;i++){
        long temp=min(suff[i],pref[i])-arr[i];
        ans+=temp;
    }
    return ans;
}
