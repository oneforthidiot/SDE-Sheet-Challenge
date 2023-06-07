int calculateMinPatforms(int at[], int dt[], int n) {
    vector<int> hash(2365,0);
    for(int i=0;i<n;i++){
        hash[at[i]]++;
        hash[dt[i]+1]--;
    }
    for(int i=1;i<=2360;i++){
        hash[i]+=hash[i-1];
    }
    int ans=*max_element(hash.begin(),hash.end());
    return ans;
}
