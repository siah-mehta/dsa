
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev = countAndSay(n - 1);
        string ans;

        for (int i = 0; i < prev.size(); i++) {
            int count = 1;

            while (i + 1 < prev.size() && prev[i] == prev[i + 1]) {
                count++;
                i++;
            }

            ans += to_string(count) + prev[i];
        }

        return ans;
    }
};
