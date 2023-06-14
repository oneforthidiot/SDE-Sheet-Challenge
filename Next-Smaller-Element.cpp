#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n){
    vector<int> nse(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(st.size() and arr[st.top()]>arr[i]){
            nse[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    return nse;
}
