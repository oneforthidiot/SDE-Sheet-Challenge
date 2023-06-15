#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack{
	// Write your code here.
	
	public:
		
		// Constructor
		vector<pair<int,int>> st;
		minStack(){ 
			st.clear();
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num){
			if(!st.size()){
				st.push_back({num,num});
			}
			else{
				st.push_back({num,min(num,st.back().second)});
			}
		}
		
		// Function to remove the top element of the stack.
		int pop(){
			if(!st.size())return -1;
			int ret=st.back().first;
			st.pop_back();
			return ret;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top(){
			if(st.size()==0)return -1;
			return st.back().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin(){
			if(!st.size())return -1;
			return st.back().second;
		}
};
