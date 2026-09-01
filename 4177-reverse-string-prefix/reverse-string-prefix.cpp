class Solution {
public:
    string reversePrefix(string s, int k) {
        string a = s.substr(0,k);
        reverse(a.begin(),a.end());
        string b = s.substr(k);
        return a+b;
    }
};