class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Iterate backward to find the longest matching prefix (0 to i-1) 
        // where we can place a character strictly greater than target[i]
        for (int i = n - 1; i >= 0; i--) {
            vector<int> current_count = count;
            bool possible = true;

            // Step 1: Check if target[0 ... i-1] can be formed from available chars
            for (int j = 0; j < i; j++) {
                if (current_count[target[j] - 'a'] > 0) {
                    current_count[target[j] - 'a']--;
                } else {
                    possible = false;
                    break;
                }
            }

            if (!possible) continue;

            // Step 2: Try placing the smallest available char greater than target[i]
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (current_count[c] > 0) {
                    string ans = target.substr(0, i);
                    ans += static_cast<char>('a' + c);
                    current_count[c]--;

                    // Step 3: Append remaining characters in ascending order
                    for (int r = 0; r < 26; r++) {
                        ans.append(current_count[r], 'a' + r);
                    }
                    return ans;
                }
            }
        }

        return "";
    }
};