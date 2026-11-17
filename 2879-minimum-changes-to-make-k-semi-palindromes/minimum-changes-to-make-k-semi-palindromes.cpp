
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // cost[l][r] = minimum changes to make s[l...r]
        // a semi-palindrome.
        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {

                int len = r - l + 1;

                // Try every proper divisor of len.
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    // Compare mirrored characters in each group.
                    for (int offset = 0; offset < d; offset++) {
                        int left = l + offset;
                        int right = r - (d - 1 - offset);

                        while (left < right) {
                            if (s[left] != s[right]) {
                                changes++;
                            }

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // dp[i][j] = minimum cost to partition
        // first i characters into exactly j parts.
        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            for (int i = 2 * parts; i <= n; i++) {

                // Last substring is s[p...i-1].
                for (int p = 2 * (parts - 1);
                     p <= i - 2; p++) {

                    if (dp[p][parts - 1] == INF) {
                        continue;
                    }

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[p][parts - 1] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
