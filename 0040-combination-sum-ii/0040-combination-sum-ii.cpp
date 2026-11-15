
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> current;

        function<void(int, int)> solve = [&](int index, int sum) {
            if (sum == target) {
                ans.push_back(current);
                return;
            }

            for (int i = index; i < candidates.size(); i++) {
                if (i > index && candidates[i] == candidates[i - 1]) continue;
                if (sum + candidates[i] > target) break;

                current.push_back(candidates[i]);
                solve(i + 1, sum + candidates[i]);
                current.pop_back();
            }
        };

        solve(0, 0);
        return ans;
    }
};
