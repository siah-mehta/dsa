class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> a;
        
        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i});
        
        sort(a.begin(), a.end());
        
        vector<vector<int>> groups;
        vector<int> current;
        
        current.push_back(a[0].second);
        
        for (int i = 1; i < n; i++) {
            if (a[i].first - a[i - 1].first <= limit) {
                current.push_back(a[i].second);
            } else {
                groups.push_back(current);
                current.clear();
                current.push_back(a[i].second);
            }
        }
        
        groups.push_back(current);
        
        vector<int> ans = nums;
        
        for (auto& group : groups) {
            vector<int> indices = group;
            sort(indices.begin(), indices.end());
            
            vector<int> values;
            for (int idx : group)
                values.push_back(nums[idx]);
            
            sort(values.begin(), values.end());
            
            for (int i = 0; i < indices.size(); i++)
                ans[indices[i]] = values[i];
        }
        
        return ans;
    }
};