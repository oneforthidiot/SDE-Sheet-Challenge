#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   sort(arr.begin(),arr.end());
   int l=0,r=arr.size()-1;
   vector<vector<int>> ans;
   while(l<r){
      if(arr[l]+arr[r]>s){
         r--;
      }
      else
      if(arr[l]+arr[r]<s){
         l++;
      }
      else{
         // arr[low]==arr[high]
         if(arr[l]==arr[r]){
            int sz=r-l+1;
            int sub=sz*(sz-1)/2;
            while(sub--){
               ans.push_back({arr[l],arr[r]});
            }
            break;
         }
         else{
            int i=l+1,j=r-1;
            int c1=1,c2=1;
            while(arr[i]==arr[l]){
               i++;
               c1++;
            }
            while(arr[r]==arr[j]){
               j--;
               c2++;
            }
            int sz=c1*c2;
            while(sz--){
               ans.push_back({arr[l],arr[r]});
            }
            l=i;
            r=j;
         }
      }
   }
   return ans;
}
