class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0) return false;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('|| s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.size()==0) return false;
                else if(st.top()=='(' && s[i]==')') st.pop();
                else if(st.top()=='[' && s[i]==']') st.pop();
                else if(st.top()=='{' && s[i]=='}') st.pop();
                else return false;
            }
        }
        if(st.size()==0) return true;
        else return false;
    }
};