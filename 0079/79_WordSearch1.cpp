#include "../inc.h"

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (helper(board, word, 0, word.size(), m, n, i, j)) return true;
                }
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, const string& word, int start, int wsize, int m, int n, int x, int y) {
        ++start;
        if (start == wsize) {
            return true;
        }
        char tmp = board[x][y];
        board[x][y] = '0';
        if (x > 0 && board[x - 1][y] == word[start]) {
            if (helper(board, word, start, wsize, m, n, x - 1, y)) return true;
        }
        if (x < m - 1 && board[x + 1][y] == word[start]) {
            if (helper(board, word, start, wsize, m, n, x + 1, y)) return true;
        }
        if (y > 0 && board[x][y - 1] == word[start]) {
            if (helper(board, word, start, wsize, m, n, x, y - 1)) return true;
        }
        if (y < n - 1 && board[x][y + 1] == word[start]) {
            if (helper(board, word, start, wsize, m, n, x, y + 1)) return true;
        }
        board[x][y] = tmp;
        return false;
    }
};

void test(vector<vector<char>>&& board, const string& word, bool expect) {
    save4print(board, word);
    assert_eq_ret(expect, Solution().exist(board, word));
}

int main() {
    test({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "ABCCED", true);
    test({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "SEE", true);
    test({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "ABCB", false);
    return 0;
}
