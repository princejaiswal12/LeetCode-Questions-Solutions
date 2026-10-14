class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = "";
        for(int i = 0;i<num;i++){
            int d = min(9,sum);
            s.push_back('0'+d);
            sum -= d;
        }
        if(sum>0) return "";
        return s;
    }
};