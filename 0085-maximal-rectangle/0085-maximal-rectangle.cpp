
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }

            stack<int> st;

            for (int j = 0; j <= n; j++) {
                int curr = (j == n ? 0 : heights[j]);

                while (!st.empty() && heights[st.top()] > curr) {
                    int h = heights[st.top()];
                    st.pop();

                    int width = st.empty() ? j : j - st.top() - 1;
                    ans = max(ans, h * width);
                }

                st.push(j);
            }
        }

        return ans;
    }
};
