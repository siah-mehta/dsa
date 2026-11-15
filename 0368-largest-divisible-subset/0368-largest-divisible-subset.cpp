class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n, 1), parent(n);
        int best = 0, last = 0;

        for (int i = 0; i < n; i++) {
            parent[i] = i;

            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if (dp[i] > best) {
                best = dp[i];
                last = i;
            }
        }

        vector<int> ans;

        while (parent[last] != last) {
            ans.push_back(nums[last]);
            last = parent[last];
        }

        ans.push_back(nums[last]);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};