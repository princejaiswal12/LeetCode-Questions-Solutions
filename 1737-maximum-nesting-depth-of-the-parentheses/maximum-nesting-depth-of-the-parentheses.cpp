class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int dep = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
                int n = st.size();
                dep = max(dep,n);
            }
            else if(s[i]==')'){
                st.pop();
            }
        }
        return dep;
    }
};