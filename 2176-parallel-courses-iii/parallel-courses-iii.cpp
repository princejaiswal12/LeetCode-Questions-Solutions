class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n + 1);
        vector<int> in(n + 1, 0);

        for (auto &r : relations) {
            int a = r[0];
            int b = r[1];

            adj[a].push_back(b);
            in[b]++;
        }

        queue<int> q;
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                q.push(i);
                dp[i] = time[i - 1];
            }
        }

        int ans = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ans = max(ans, dp[u]);

            for (int v : adj[u]) {
                dp[v] = max(dp[v], dp[u] + time[v - 1]);

                in[v]--;

                if (in[v] == 0) {
                    q.push(v);
                }
            }
        }

        return ans;
    }
};