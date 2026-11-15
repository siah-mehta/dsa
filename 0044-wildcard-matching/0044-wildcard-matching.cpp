class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> dp(m + 1, false);
        dp[0] = true;

        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') dp[j] = dp[j - 1];
        }

        for (int i = 1; i <= n; i++) {
            vector<bool> curr(m + 1, false);

            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    curr[j] = curr[j - 1] || dp[j];
                } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    curr[j] = dp[j - 1];
                }
            }

            dp = curr;
        }

        return dp[m];
    }
};