class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int maxi = 0;

            for (int len = 1; len <= k && i + len <= n; len++) {
                maxi = max(maxi, arr[i + len - 1]);
                dp[i] = max(dp[i], maxi * len + dp[i + len]);
            }
        }

        return dp[0];
    }
};