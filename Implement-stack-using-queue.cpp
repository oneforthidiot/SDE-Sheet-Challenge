#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
   public:
   queue<int> q1,q2;
   int size=0;
    Stack() {
        size=0;
        // qt1.clear();
        // qt2.clear();
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }


    bool isEmpty() {
        return size==0;
    }

    void push(int element) {
        q2.push(element);
        while(!q1.empty()){

            int val = q1.front();
            q1.pop();
            q2.push(val);
        }
        swap(q1, q2);
        size++;
    }
    int pop(){
        if(!q1.empty()){
            int val = q1.front();
            q1.pop();
            size--;
            return val;
        }
        else{
            return -1;
        }
    }
    int top(){
        if(!q1.empty()){
            return q1.front();
        }
        else{
           return -1;
        }
    }
};
