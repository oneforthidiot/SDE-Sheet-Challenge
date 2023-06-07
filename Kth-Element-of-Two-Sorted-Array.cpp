#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    if(m>n)return ninjaAndLadoos(row2, row1, n, m, k);
    //
    if(k==1)return min(row1[0],row2[0]);
    // if(k==2)return max(row1[0],row2[0]);
    int l=max(0,k-n);
    int r=min(k,m);
    while(l<=r){
        int mid=(l+r)/2;
        int mid1=k-mid;
        int l1=(mid-1>=0)?row1[mid-1]:INT_MIN;
        int l2=(mid1-1>=0)?row2[mid1-1]:INT_MIN;
        int r1=(mid<m)?row1[mid]:INT_MAX;
        int r2=(mid1<n)?row2[mid1]:INT_MAX;
        if(l1<=r2 and l2<=r1){
            return max(l1,l2);
        }
        else
        if(l1>r2){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return 1;
}
