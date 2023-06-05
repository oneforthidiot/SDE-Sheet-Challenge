#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    set<char> st;
    int n=input.size();
    int ans=1;
    int i=0,j=0;
    while(j<n){
        if(st.find(input[j])==st.end()){
            st.insert(input[j]);
            j++;
        }
        else{
            st.erase(input[i]);
            i++;
        }
        int sz=st.size();
        ans=max(ans,sz);
    }
    return ans;
}
