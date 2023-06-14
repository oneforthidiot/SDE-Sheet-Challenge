#include <bits/stdc++.h> 
void rec2(stack<int> &st,int x){
	if(!st.size() or st.top()<x){
		st.push(x);
		return;
	}
	int temp=st.top();
	st.pop();
	rec2(st,x);
	st.push(temp);
}
void rec1(stack<int> &st){
	if(!st.size())return;
	int tp=st.top();
	st.pop();
	rec1(st);
	rec2(st,tp);
}
void sortStack(stack<int> &stack){
	rec1(stack);
}
