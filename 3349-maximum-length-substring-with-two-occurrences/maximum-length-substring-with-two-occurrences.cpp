class Solution {
public:
    int maximumLengthSubstring(string s) {
        int j = 0;
        int ans = 0;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            if(m[s[i]]>2){
                while(m[s[i]]>2){
                    m[s[j]]--;
                    j++;
                }
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};