class Solution {
public:
    using ll = long long;

    int m, n;
    vector<vector<pair<ll, ll>>> t;

    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid) {

        // Base case: destination
        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }

        // Already calculated
        if (t[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) {
            return t[i][j];
        }

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        // Move Down
        if (i + 1 < m) {
            auto [downMax, downMin] = solve(i + 1, j, grid);

            maxVal = max({
                maxVal,
                1LL * grid[i][j] * downMax,
                1LL * grid[i][j] * downMin
            });

            minVal = min({
                minVal,
                1LL * grid[i][j] * downMax,
                1LL * grid[i][j] * downMin
            });
        }

        // Move Right
        if (j + 1 < n) {
            auto [rightMax, rightMin] = solve(i, j + 1, grid);

            maxVal = max({
                maxVal,
                1LL * grid[i][j] * rightMax,
                1LL * grid[i][j] * rightMin
            });

            minVal = min({
                minVal,
                1LL * grid[i][j] * rightMax,
                1LL * grid[i][j] * rightMin
            });
        }

        return t[i][j] = {maxVal, minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // Initialize memoization table
        t = vector<vector<pair<ll, ll>>>(
            m,
            vector<pair<ll, ll>>(
                n,
                {LLONG_MIN, LLONG_MAX}
            )
        );

        auto [maxProd, minProd] = solve(0, 0, grid);

        if (maxProd < 0)
            return -1;

        return maxProd % 1000000007;
    }
};