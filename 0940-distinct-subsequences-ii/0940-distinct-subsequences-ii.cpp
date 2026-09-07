class Solution {
public:
    int distinctSubseqII(string s) {

        const long long MOD = 1e9 + 7;

        // last[c] = number of distinct subsequences
        // before the previous occurrence of c
        vector<long long> last(26, 0);

        long long dp = 1; // empty subsequence

        for (char c : s) {

            long long old = dp;

            dp = (2 * dp - last[c - 'a'] + MOD) % MOD;

            last[c - 'a'] = old;
        }

        // Remove empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};