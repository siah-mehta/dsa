class Solution {
public:
    struct State {
        int r, c;
        int mask;
        int energy;
    };

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        vector<pair<int, int>> litter;
        vector<vector<int>> id(m, vector<int>(n, -1));

        int sr = -1, sc = -1;

        // Find start and assign IDs to litter
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                }

                if (classroom[r][c] == 'L') {
                    id[r][c] = litter.size();
                    litter.push_back({r, c});
                }
            }
        }

        int k = litter.size();

        // No litter to collect
        if (k == 0)
            return 0;

        int fullMask = (1 << k) - 1;

        // best[r][c][mask] = maximum energy
        // with which we have reached this state
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << k, -1)
            )
        );

        queue<State> q;

        q.push({sr, sc, 0, energy});

        best[sr][sc][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                State cur = q.front();
                q.pop();

                int r = cur.r;
                int c = cur.c;
                int mask = cur.mask;
                int e = cur.energy;

                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter
                    if (id[nr][nc] != -1) {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    // If this state is not better, skip it
                    if (best[nr][nc][nmask] >= ne)
                        continue;

                    best[nr][nc][nmask] = ne;

                    q.push({
                        nr,
                        nc,
                        nmask,
                        ne
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};