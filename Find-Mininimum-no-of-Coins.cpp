#include <bits/stdc++.h> 
int findMinimumCoins(int amount) {
    vector<int> arr={1000,500,100,50,20,10,5,2,1};
    int ans=0;
    for(int i=0;i<arr.size();i++){
        if(amount>=arr[i]){
            ans+=(amount/arr[i]);
            amount=amount%arr[i];
        }
    }
    return ans;
}
