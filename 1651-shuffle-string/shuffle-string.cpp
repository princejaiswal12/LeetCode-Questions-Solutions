class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<pair<int,char>> v;
        for(int i=0;i<s.size();i++){
            v.push_back({indices[i],s[i]});
        }
        sort(v.begin(),v.end());
        string a = "";
        for(int i=0;i<v.size();i++){
            a += v[i].second;
        }
        return a;
    }
};