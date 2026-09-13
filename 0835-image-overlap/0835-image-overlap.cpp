class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {
        
        int n = img1.size();

        vector<pair<int, int>> ones1;
        vector<pair<int, int>> ones2;

        // Store coordinates of 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    ones1.push_back({i, j});

                if (img2[i][j] == 1)
                    ones2.push_back({i, j});
            }
        }

        map<pair<int, int>, int> cnt;

        int ans = 0;

        // Try every pair of 1s
        for (auto [r1, c1] : ones1) {
            for (auto [r2, c2] : ones2) {

                int dx = r2 - r1;
                int dy = c2 - c1;

                cnt[{dx, dy}]++;

                ans = max(ans, cnt[{dx, dy}]);
            }
        }

        return ans;
    }
};