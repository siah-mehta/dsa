class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [effort, r, c] = pq.top();
            pq.pop();

            if (effort > dist[r][c]) continue;
            if (r == m - 1 && c == n - 1) return effort;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newEffort = max(effort, abs(heights[r][c] - heights[nr][nc]));

                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};