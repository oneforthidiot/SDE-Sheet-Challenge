#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    vector<int> arr;
    int sz=0;
    Stack(int capacity) {
        arr.clear();
        sz=capacity;
        // Write your code here.
    }

    void push(int num) {
        arr.push_back(num);
        // Write your code here.
    }

    int pop() {
        int ret=(arr.size())?arr.back():-1;
        if(arr.size())arr.pop_back();
        return ret;
        // Write your code here.
    }
    
    int top() {
        // Write your code here.
        int ret=(arr.size())?arr.back():-1;
        return ret;
    }
    
    int isEmpty() {
        return arr.size()==0;
        // Write your code here.
    }
    
    int isFull() {
        return arr.size()==sz;
        // Write your code here.
    }
    
};
