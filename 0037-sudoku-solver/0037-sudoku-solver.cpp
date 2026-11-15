
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(10, 0));
        vector<vector<int>> col(9, vector<int>(10, 0));
        vector<vector<int>> box(9, vector<int>(10, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = 1;
                    col[j][num] = 1;
                    box[(i / 3) * 3 + j / 3][num] = 1;
                }
            }
        }

        function<bool()> solve = [&]() {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        int b = (i / 3) * 3 + j / 3;

                        for (int num = 1; num <= 9; num++) {
                            if (!row[i][num] && !col[j][num] && !box[b][num]) {
                                board[i][j] = num + '0';
                                row[i][num] = 1;
                                col[j][num] = 1;
                                box[b][num] = 1;

                                if (solve()) return true;

                                board[i][j] = '.';
                                row[i][num] = 0;
                                col[j][num] = 0;
                                box[b][num] = 0;
                            }
                        }

                        return false;
                    }
                }
            }

            return true;
        };

        solve();
    }
};
