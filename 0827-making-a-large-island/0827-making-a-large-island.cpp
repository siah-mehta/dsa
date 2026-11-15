class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> id(n, vector<int>(n, 0));
        vector<int> area(1, 0);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        function<int(int, int, int)> dfs = [&](int r, int c, int idx) {
            id[r][c] = idx;
            int count = 1;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    grid[nr][nc] == 1 && id[nr][nc] == 0) {
                    count += dfs(nr, nc, idx);
                }
            }

            return count;
        };

        int idx = 0;
        int answer = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && id[i][j] == 0) {
                    idx++;
                    area.push_back(dfs(i, j, idx));
                    answer = max(answer, area[idx]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int candidate = 1;

                    for (int k = 0; k < 4; k++) {
                        int nr = i + dr[k], nc = j + dc[k];

                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            int component = id[nr][nc];

                            if (component && seen.insert(component).second) {
                                candidate += area[component];
                            }
                        }
                    }

                    answer = max(answer, candidate);
                }
            }
        }

        return answer == 0 ? n * n : answer;
    }
};