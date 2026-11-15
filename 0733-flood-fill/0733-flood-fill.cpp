class Solution {
public:
    void dfs(int r, int c, int color, int original, vector<vector<int>>& image) {
        int m = image.size(), n = image[0].size();

        image[r][c] = color;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == original) {
                dfs(nr, nc, color, original, image);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];

        if (original != color) {
            dfs(sr, sc, color, original, image);
        }

        return image;
    }
};