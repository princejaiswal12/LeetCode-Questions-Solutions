class Solution {
public:
   
    int maxFreqSum(string s) {
        unordered_map<char,int> m;
        int fv = 0,fc = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' ||s[i]=='i' || s[i]=='o' || s[i]=='u'){
                m[s[i]]++;
                fc = max(m[s[i]],fc);
            }else{
                m[s[i]]++;
                fv = max(m[s[i]],fv);
            }
        }
        return fc + fv;
    }
};