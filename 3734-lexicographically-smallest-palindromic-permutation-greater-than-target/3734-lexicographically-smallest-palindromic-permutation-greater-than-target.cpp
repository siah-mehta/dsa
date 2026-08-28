class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Count characters
        vector<int> cnt(26, 0);

        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        // A palindrome can have at most one odd frequency
        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

        // Number of copies available for the left half
        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        int halfLen = n / 2;

        string prefix;

        /*
            Try to construct the left half greedily.

            For every position:
            - Try 'a' to 'z'
            - Temporarily choose it
            - Complete the remaining left half in DESCENDING
              order to get the largest possible palindrome
            - If that largest palindrome is still <= target,
              this choice can never work.
        */

        for (int pos = 0; pos < halfLen; pos++) {

            bool chosen = false;

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                // Choose this character
                half[c]--;
                prefix.push_back(char('a' + c));

                // Build the largest possible left half
                string left = prefix;

                for (int x = 25; x >= 0; x--) {
                    left.append(
                        half[x],
                        char('a' + x)
                    );
                }

                // Build the palindrome
                string right = left;
                reverse(right.begin(), right.end());

                string candidate;

                if (n % 2 == 1) {
                    candidate =
                        left +
                        string(1, middle) +
                        right;
                }
                else {
                    candidate = left + right;
                }

                /*
                    If the largest palindrome possible with
                    this prefix is > target, then SOME valid
                    answer exists with this prefix.
                */
                if (candidate > target) {

                    chosen = true;
                    break;

                } else {

                    // This character cannot lead to an answer
                    half[c]++;
                    prefix.pop_back();
                }
            }

            // No character can work at this position
            if (!chosen) {
                return "";
            }
        }

        // Construct final answer
        string right = prefix;
        reverse(right.begin(), right.end());

        string answer;

        if (n % 2 == 1) {
            answer =
                prefix +
                string(1, middle) +
                right;
        }
        else {
            answer = prefix + right;
        }

        return answer > target ? answer : "";
    }
};