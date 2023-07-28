#include <algorithm>

class Kthlargest {
public:
    multiset<int> mst;
    int K;
    Kthlargest(int k, vector<int> &arr) {
        K=k;
        for(auto it:arr){
            mst.insert(it);
            if(mst.size()>k)mst.erase(mst.begin());
        }
    }

    int add(int num) {
        mst.insert(num);
        if(mst.size()>K)mst.erase(mst.begin());
        return *mst.begin();
    }

};
