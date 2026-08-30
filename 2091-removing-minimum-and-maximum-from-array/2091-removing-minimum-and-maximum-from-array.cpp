class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = min_element(nums.begin(), nums.end()) - nums.begin();
        int mx = max_element(nums.begin(), nums.end()) - nums.begin();

        int a = min(mn, mx);
        int b = max(mn, mx);

        int left = b + 1;
        int right = n - a;
        int both = (a + 1) + (n - b);

        return min({left, right, both});
    }
};