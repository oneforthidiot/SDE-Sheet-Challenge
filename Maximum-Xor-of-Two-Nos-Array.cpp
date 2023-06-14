#include <bits/stdc++.h> 
int maximumXor(vector<int> arr){
     // 010
     // 001
     // 100
     int n=arr.size();
     int ans=0;
     int mask=0;
     for(int i=31;i>=0;i--){
          mask|=(1<<i);
          set<int> st;
          for(int j=0;j<n;j++){
               st.insert(arr[j]&mask);
          }
          int temp=(ans|(1<<i));
          for(auto it:st){
               if(st.find(temp^it)!=st.end()){
                    ans=temp;
                    break;
               }
          }
            
     }
     return ans;
}
