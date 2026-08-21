class Solution {
public:
    long long gcdll(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcmll(long long a, long long b) {
        return a / gcdll(a, b) * b;
    }

    long long countNumbers(long long x, vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcm = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    lcm = lcmll(lcm, coins[i]);

                    // No need to continue if LCM > x
                    if (lcm > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            long long contribution = x / lcm;

            if (bits % 2 == 1)
                count += contribution;
            else
                count -= contribution;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo = 1;
        long long hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (countNumbers(mid, coins) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};