class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, INT_MAX);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[j] = grid[i][j];
                } else {
                    int up = dp[j];
                    int left = j > 0 ? dp[j - 1] : INT_MAX;
                    dp[j] = grid[i][j] + min(up, left);
                }
            }
        }

        return dp[n - 1];
    }
};