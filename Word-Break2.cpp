#include <bits/stdc++.h> 
vector<string> ans;
void rec(string &s,string temp,int idx,map<string,int> &mp){
    if(idx==s.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=idx;i<s.size();i++){
        string t=s.substr(idx,i-idx+1);
        if(mp.find(t)!=mp.end()){
            int sz=temp.size();
            temp+=(t+" ");
            rec(s,temp,i+1,mp);
            temp.erase(sz);
        }

    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary){
    ans.clear();
    string temp="";
    map<string,int> mp;
    for(auto it:dictionary)mp[it]++;
    rec(s,temp,0,mp);
    return ans;
}
