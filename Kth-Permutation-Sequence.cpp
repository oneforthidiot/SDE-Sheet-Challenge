string kthPermutation(int n, int k) {
    int fact=1;
    vector<int> num;
    for(int i=1;i<n;i++){
        fact*=i;
        num.push_back(i);
    }
    num.push_back(n);
    string ans="";
    k--;
    while(num.size()){
        int temp=k/fact;
        ans+=to_string(num[temp]);
        num.erase(num.begin()+temp);
        if(num.size()==0)break;
        k=k%fact;
        if(num.size())fact/=num.size();
    }
    return ans;
}
