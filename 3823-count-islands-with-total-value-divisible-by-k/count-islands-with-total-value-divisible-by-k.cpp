class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        vector<vector<int>> d = {{0,-1},{0,1},{-1,0},{1,0}};

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] > 0 && !vis[i][j]) {

                    long long sum = 0;

                    q.push({i,j});
                    vis[i][j] = 1;

                    while(!q.empty()) {

                        auto [x,y] = q.front();
                        q.pop();

                        sum += grid[x][y];

                        for(int dir = 0; dir < 4; dir++) {
                            int nx = x + d[dir][0];
                            int ny = y + d[dir][1];

                            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                                continue;
                            if(vis[nx][ny] || grid[nx][ny] == 0)
                                continue;

                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }

                    if(sum % k == 0)
                        cnt++;
                }
            }
        }

        return cnt;
    }
};