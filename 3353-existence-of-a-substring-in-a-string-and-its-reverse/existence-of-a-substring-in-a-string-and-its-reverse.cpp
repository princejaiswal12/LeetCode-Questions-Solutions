class Solution {
public:
    bool isSubstringPresent(string s) {
        string t = s;
        int n = s.size();
        reverse(s.begin(),s.end());
        unordered_map<string,int> m;
        for(int i=0;i<n-1;i++){
            m[s.substr(i,2)]++;
        }
        for(int i=0;i<n-1;i++){
            if(m[t.substr(i,2)]) return true;
        }
        return false;
    }
};