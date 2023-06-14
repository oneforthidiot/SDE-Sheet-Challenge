 #include<bits/stdc++.h>
 int largestRectangle(vector < int > & heights) {
   stack<int> st;
   int ans=0;
   int n=heights.size();
   int i=0;
   while(i<n){
     if(!st.size() or heights[st.top()]<=heights[i]){
       st.push(i);
       i++;
     }
     else{
       int ft=st.top();
       st.pop();
       int temp=heights[ft]*((st.size())?(i-st.top()-1):i);
       ans=max(ans,temp);
     }
   }
   while(st.size()){
      int ft=st.top();
      st.pop();
      int temp=heights[ft]*((st.size())?(i-st.top()-1):i);
      ans=max(ans,temp);
   }
   return ans;
 }
