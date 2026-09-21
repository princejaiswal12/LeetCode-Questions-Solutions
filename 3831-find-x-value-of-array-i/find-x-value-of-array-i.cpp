class Solution {
public:
    int n, k;
    vector<int> nums;
    vector<vector<long long>> memo;

    vector<long long> dfs(int i) {
        if (i < 0)
            return vector<long long>(k, 0);

        if (memo[i][0] != -1) {
            return memo[i];
        }

        vector<long long> cur(k, 0);

        // Subarray consisting only of nums[i]
        int x = nums[i] % k;
        cur[x]++;

        // Extend every subarray ending at i-1
        vector<long long> prev = dfs(i - 1);

        for (int r = 0; r < k; r++) {
            int nr = (r * x) % k;
            cur[nr] += prev[r];
        }

        return memo[i] = cur;
    }

    vector<long long> resultArray(vector<int>& nums, int k) {
        this->nums = nums;
        this->k = k;
        n = nums.size();

        memo.assign(n, vector<long long>(k, -1));

        vector<long long> total(k, 0);

        for (int i = 0; i < n; i++) {
            vector<long long> cur = dfs(i);

            for (int r = 0; r < k; r++) {
                total[r] += cur[r];
            }
        }

        vector<long long> ans(k);

        for (int r = 0; r < k; r++)
            ans[r] = total[r];

        return ans;
    }
};