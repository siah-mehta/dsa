class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        grid[r][c] = '0';

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
                dfs(nr, nc, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;

        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
};