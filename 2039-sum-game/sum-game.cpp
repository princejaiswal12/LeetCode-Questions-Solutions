class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();

        int ls = 0, rs = 0;
        int lq = 0, rq = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < n / 2)
                    lq++;
                else
                    rq++;
            }
            else {
                if (i < n / 2)
                    ls += num[i] - '0';
                else
                    rs += num[i] - '0';
            }
        }

        int q = lq + rq;

        if (q % 2 == 1)
            return true;

        int left = 2 * ls + 9 * lq;
        int right = 2 * rs + 9 * rq;

        return left != right;
    }
};