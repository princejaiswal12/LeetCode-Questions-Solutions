class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<bool> seen(101, false);
        vector<bool> bad(101, false);

        int prev = -1;

        for (int x : nums) {
            if (seen[x] && prev != x) {
                // x appeared before, but its block was interrupted
                bad[x] = true;
            }

            seen[x] = true;
            prev = x;
        }

        int ans = 0;

        for (int x = 1; x <= 100; x++) {
            if (seen[x] && !bad[x]) {
                ans++;
            }
        }

        return ans;
    }
};