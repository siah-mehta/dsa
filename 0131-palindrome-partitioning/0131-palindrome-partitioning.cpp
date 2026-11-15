
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;
        int n = s.size();

        auto isPalindrome = [&](int left, int right) {
            while (left < right) {
                if (s[left] != s[right]) return false;
                left++;
                right--;
            }
            return true;
        };

        function<void(int)> solve = [&](int index) {
            if (index == n) {
                ans.push_back(current);
                return;
            }

            for (int i = index; i < n; i++) {
                if (isPalindrome(index, i)) {
                    current.push_back(s.substr(index, i - index + 1));
                    solve(i + 1);
                    current.pop_back();
                }
            }
        };

        solve(0);
        return ans;
    }
};
