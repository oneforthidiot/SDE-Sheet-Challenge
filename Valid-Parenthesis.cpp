bool isValidParenthesis(string s){
    stack<char> st;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='[' or s[i]=='{' or s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(!st.size())return false;
            if(s[i]=='}' and st.top()=='{'){
                st.pop();
            }
            else
            if(s[i]==']' and st.top()=='['){
                st.pop();
            }
            else
            if(s[i]==')' and st.top()=='('){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    if(st.size())return false;
    return true;
}
