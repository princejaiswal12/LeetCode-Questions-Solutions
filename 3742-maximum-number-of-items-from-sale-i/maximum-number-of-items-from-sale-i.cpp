class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freeCount(n, 0);

        // Calculate free items for each item type
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeCount[i]++;
                }
            }
        }

        // dp[b] = maximum items obtainable with budget b
        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int free = freeCount[i];

            // Buy this item at least once
            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + 1 + free);
            }

            // Buy additional copies of this item
            for (int b = price; b <= budget; b++) {
                dp[b] = max(dp[b], dp[b - price] + 1);
            }
        }

        return dp[budget];
    }
};