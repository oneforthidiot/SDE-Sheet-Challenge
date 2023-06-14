#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> nge(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(st.size() and arr[st.top()]<arr[i]){
            nge[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    return nge;

}
