class Solution {
public:
    vector<int> topoSort(int k, vector<vector<int>>& conditions) {
        vector<vector<int>> adj(k + 1);
        vector<int> indegree(k + 1, 0);

        for (auto &v : conditions) {
            int u = v[0];
            int w = v[1];

            adj[u].push_back(w);
            indegree[w]++;
        }

        queue<int> q;

        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            order.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Cycle exists
        if (order.size() != k)
            return {};

        return order;
    }

    vector<vector<int>> buildMatrix(
        int k,
        vector<vector<int>>& rowConditions,
        vector<vector<int>>& colConditions
    ) {
        // Topological order for rows
        vector<int> rowOrder = topoSort(k, rowConditions);

        // Topological order for columns
        vector<int> colOrder = topoSort(k, colConditions);

        // If either graph contains a cycle
        if (rowOrder.empty() || colOrder.empty())
            return {};

        // row[x] = row index of number x
        // col[x] = column index of number x
        vector<int> row(k + 1);
        vector<int> col(k + 1);

        for (int i = 0; i < k; i++) {
            row[rowOrder[i]] = i;
            col[colOrder[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));

        for (int x = 1; x <= k; x++) {
            ans[row[x]][col[x]] = x;
        }

        return ans;
    }
};