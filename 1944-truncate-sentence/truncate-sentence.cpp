class Solution {
public:
    string truncateSentence(string s, int k) {
        int c = 0;
        int idx = -1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') c++;
            if(c==k){
                idx = i;
                break;
            }
        }
        return s.substr(0,idx);
    }
};