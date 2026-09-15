class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = maximum number of non-overlapping
        // palindromes from index i onward
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            // Skip current character
            dp[i] = dp[i + 1];

            // Take a palindrome starting at i
            for (int j = i; j < n; j++) {
                if (j - i + 1 >= k && pal[i][j]) {
                    dp[i] = max(dp[i], 1 + dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};