class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        auto solve = [&](int start, int end) {
            int prev2 = 0, prev1 = 0;

            for (int i = start; i <= end; i++) {
                int curr = max(prev1, prev2 + nums[i]);
                prev2 = prev1;
                prev1 = curr;
            }

            return prev1;
        };

        return max(solve(0, n - 2), solve(1, n - 1));
    }
};