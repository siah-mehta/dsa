
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        unordered_map<int, int> mp;
        int left = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;

            while (mp.size() > k) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};
