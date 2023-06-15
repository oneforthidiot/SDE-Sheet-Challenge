#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // next greater to left
    int n=price.size();
    vector<int> ans(n);
    vector<int> ngl(n,0);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(st.size() and price[st.top()]<price[i]){
            ngl[st.top()]=i+1;
            st.pop();
        }
        st.push(i);
    }
    for(int i=0;i<n;i++){
        ans[i]=(i+1-ngl[i]);
        // cout<<ngl[i]<<" ";
    }
    // cout<<endl;
    return ans;
    

}
