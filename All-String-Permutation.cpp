#include <bits/stdc++.h> 

void func(string &s, int index, vector<string> &ans){
    if (index == s.length()){
        ans.push_back(s);
        return;
    }
    for(int i=index;i<s.length();i++){
        swap(s[i],s[index]);
        func(s, index + 1 , ans);
        swap(s[i],s[index]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    func(s, 0, ans);
    return ans;
}
// #include <bits/stdc++.h> 

// void helper(string &s,int l,int r,vector<string> &ans){
//     if(l==r){
//         ans.push_back(s);
//         return;
//     }
//     for(int i=l;i<=r;i++){
//         swap(s[l],s[i]);
//         helper(s,i+1,r,ans);
//         swap(s[l],s[i]);
//     }
// }
// vector<string> findPermutations(string &s) {
//     int n=s.length();
//     int sz=(1<<n);
//     vector<string> ans;
//     helper(s,0,n-1,ans);
//     return ans;
// }
