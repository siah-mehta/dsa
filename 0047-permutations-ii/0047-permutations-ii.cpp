
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> current;
        vector<int> used(nums.size(), 0);

        function<void()> solve = [&]() {
            if (current.size() == nums.size()) {
                ans.push_back(current);
                return;
            }

            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) continue;

                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                    continue;

                used[i] = 1;
                current.push_back(nums[i]);

                solve();

                current.pop_back();
                used[i] = 0;
            }
        };

        solve();
        return ans;
    }
};
