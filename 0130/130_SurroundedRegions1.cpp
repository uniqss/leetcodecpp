#include "../inc.h"

class Solution {
    int m = 0;
    int n = 0;

   public:
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = board[i][j] == 'V' ? 'O' : 'X';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= m) return;
        if (y < 0 || y >= n) return;
        if (board[x][y] != 'O') return;
        board[x][y] = 'V';
        dfs(board, x + 1, y);
        dfs(board, x, y + 1);
        dfs(board, x - 1, y);
        dfs(board, x, y - 1);
    }
};

void test(vector<vector<char>>&& board, const vector<vector<char>>& expect) {
    save4print(board);
    Solution().solve(board);
    assert_eq_ret(expect, board);
}

int main() {
    test({{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}},
         {{'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'O', 'X', 'X'}});
    test({{'X'}}, {{'X'}});
    return 0;
}
