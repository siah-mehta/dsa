
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<int> col(n, 0);
        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);

        function<void(int)> solve = [&](int row) {
            if (row == n) {
                ans.push_back(board);
                return;
            }

            for (int c = 0; c < n; c++) {
                if (!col[c] && !diag1[row + c] && !diag2[row - c + n - 1]) {
                    board[row][c] = 'Q';
                    col[c] = 1;
                    diag1[row + c] = 1;
                    diag2[row - c + n - 1] = 1;

                    solve(row + 1);

                    board[row][c] = '.';
                    col[c] = 0;
                    diag1[row + c] = 0;
                    diag2[row - c + n - 1] = 0;
                }
            }
        };

        solve(0);
        return ans;
    }
};
