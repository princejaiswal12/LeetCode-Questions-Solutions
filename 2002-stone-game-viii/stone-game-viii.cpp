class Solution {
public:
    vector<long long> pre, dp;
    vector<int> vis;

    long long solve(int i, int n) {
        if (i == n) return pre[n];

        if (vis[i]) return dp[i];
        vis[i] = 1;

        // Skip this prefix
        long long skip = solve(i + 1, n);

        // Take this prefix
        long long take = pre[i] - solve(i + 1, n);

        return dp[i] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        pre.resize(n + 1);
        dp.resize(n + 1);
        vis.resize(n + 1);

        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + stones[i - 1];

        return solve(2, n);
    }
};