class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        int ans = 1;

        for (const string& word : words) {
            int best = 1;

            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(prev)) {
                    best = max(best, dp[prev] + 1);
                }
            }

            dp[word] = best;
            ans = max(ans, best);
        }

        return ans;
    }
};