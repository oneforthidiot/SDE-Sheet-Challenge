int longestSubSeg(vector<int> &arr , int n, int k){
    int zero=0;
    int i=0,j=0;
    int ans=0;
    int sz=0;
    while(j<n){
        if(arr[j]==1){
            sz++;
            j++;
        }
        else
        if(arr[j]==0){
            zero++;
            sz++;
            j++;
        }
        if(zero>k){
            while(i<j and zero>k){
                if(arr[i]==0)zero--;
                i++;
                sz--;
            }
        }
        ans=max(ans,sz);
    }
    return ans;
}
