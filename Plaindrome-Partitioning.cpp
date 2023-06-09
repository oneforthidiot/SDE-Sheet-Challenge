#include <bits/stdc++.h> 
vector<vector<string>> ans;
bool isPalin(string &s,int l,int r){
    while(l<r){
        if(s[l]!=s[r])return 0;
        l++;
        r--;
    }
    return 1;
}
void rec(string &s,int l,int r,vector<string> &temp){
    if(l==r){
        ans.push_back(temp);
        return;
    }
    for(int i=l;i<r;i++){
        if(isPalin(s,l,i)){
            temp.push_back(s.substr(l,i-l+1));
            rec(s,i+1,r,temp);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) {
    ans.clear();
    vector<string> temp;
    int n=s.length();
    rec(s,0,n,temp);
    return ans;
}
