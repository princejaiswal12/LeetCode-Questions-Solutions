class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        int zero = cnt[0];
        int one = cnt[1];
        int two = cnt[2];

        if (zero%2==0){
            return ((two>=1 && one>=1)&&(two>=one || one>=two));
        }
        return abs(one - two) >= 3;
    }
};