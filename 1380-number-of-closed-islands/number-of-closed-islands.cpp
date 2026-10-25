class Solution {
public:
    int m, n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void bfs(vector<vector<int>>& grid, int sx, int sy) {
        queue<pair<int, int>> q;
        q.push({sx, sy});
        grid[sx][sy] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Step 1: Remove boundary-connected land
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) bfs(grid, i, 0);
            if (grid[i][n - 1] == 0) bfs(grid, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0) bfs(grid, 0, j);
            if (grid[m - 1][j] == 0) bfs(grid, m - 1, j);
        }

        // Step 2: Count closed islands
        int ans = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    ans++;
                    bfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};
