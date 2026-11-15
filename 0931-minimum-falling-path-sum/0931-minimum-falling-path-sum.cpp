class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix[0];

        for (int i = 1; i < n; i++) {
            vector<int> curr(n, INT_MAX);

            for (int j = 0; j < n; j++) {
                curr[j] = matrix[i][j] + dp[j];

                if (j > 0) {
                    curr[j] = min(curr[j], matrix[i][j] + dp[j - 1]);
                }

                if (j + 1 < n) {
                    curr[j] = min(curr[j], matrix[i][j] + dp[j + 1]);
                }
            }

            dp = curr;
        }

        return *min_element(dp.begin(), dp.end());
    }
};