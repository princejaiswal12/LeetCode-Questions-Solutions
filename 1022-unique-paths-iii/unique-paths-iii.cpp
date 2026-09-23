class Solution {
public:
    int m, n, t;

    int f(int i, int j, int vis, vector<vector<int>>& grid) {

        if(grid[i][j] == 2) {
            return vis == t;
        }

        vector<vector<int>> d = {
            {0, -1},
            {0, 1},
            {1, 0},
            {-1, 0}
        };

        grid[i][j] = -1;

        int ans = 0;

        for(int k = 0; k < 4; k++) {
            int x = i + d[k][0];
            int y = j + d[k][1];

            if(x < 0 || y < 0 || x >= m || y >= n ||
               grid[x][y] == -1)
                continue;

            ans += f(x, y, vis + 1, grid);
        }

        grid[i][j] = 0;

        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        t = 0;

        int si, sj;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == -1)
                    continue;

                if(grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }

                t++;
            }
        }

        return f(si, sj, 1, grid);
    }
};