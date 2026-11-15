class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<int> dp(n, 1);

        for (int i = n - 1; i >= 0; i--) {
            int diagonal = 0;

            for (int j = i + 1; j < n; j++) {
                int old = dp[j];

                if (s[i] == s[j]) {
                    dp[j] = diagonal + 2;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }

                diagonal = old;
            }
        }

        return n - dp[n - 1];
    }
};