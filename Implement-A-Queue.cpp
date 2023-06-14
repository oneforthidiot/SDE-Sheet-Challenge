#include <bits/stdc++.h> 
class Queue {
public:
    vector<int> arr;
    Queue() {
        arr.clear();
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return arr.size()==0;
        // Implement the isEmpty() function
    }

    void enqueue(int data) {
        arr.push_back(data);
        // Implement the enqueue() function
    }

    int dequeue() {
        if(!arr.size())return -1;
        int ret=arr[0];
        arr.erase(arr.begin());
        return ret;
        // Implement the dequeue() function
    }

    int front() {
        if(arr.size()==0)return -1;
        return arr[0];
        // Implement the front() function
    }
};
