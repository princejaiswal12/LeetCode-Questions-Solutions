class Solution {
public:
    int countCommas(int n) {
        if(n<999) return 0;
        int ans = 0;
        for(int i=1000;i<=n;i++){
            string s = to_string(i);
            int digit = s.size();
            ans += (digit-1)/3;
        }
        return ans;
    }
};