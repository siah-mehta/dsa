
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> current;

        function<void(int)> solve = [&](int index) {
            ans.push_back(current);

            for (int i = index; i < nums.size(); i++) {
                if (i > index && nums[i] == nums[i - 1]) continue;

                current.push_back(nums[i]);
                solve(i + 1);
                current.pop_back();
            }
        };

        solve(0);
        return ans;
    }
};
