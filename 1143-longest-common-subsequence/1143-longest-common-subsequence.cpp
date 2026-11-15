class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> dp(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            int diagonal = 0;

            for (int j = 1; j <= m; j++) {
                int up = dp[j];

                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = diagonal + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }

                diagonal = up;
            }
        }

        return dp[m];
    }
};