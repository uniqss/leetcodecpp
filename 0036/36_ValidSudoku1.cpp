#include "../inc.h"

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> col(9);
        vector<vector<unordered_set<char>>> small(3, vector<unordered_set<char>>(3));
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> row;
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                if (row.count(c) > 0) return false;
                row.insert(c);
                if (col[i].count(c) > 0) return false;
                col[i].insert(c);
                if (small[i / 3][j / 3].count(c) > 0) return false;
                small[i / 3][j / 3].insert(c);
            }
        }
        return true;
    }
};

void test(vector<vector<char>>&& board, bool expect) {
    save4print(board);
    Solution so;
    auto ret = so.isValidSudoku(board);
    assert_eq_ret(expect, ret);
}

int main() {
    test({{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
          {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
          {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
          {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
          {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
          {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
          {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
          {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
          {'.', '.', '.', '.', '8', '.', '.', '7', '9'}},
         true);
    test({{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
          {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
          {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
          {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
          {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
          {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
          {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
          {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
          {'.', '.', '.', '.', '8', '.', '.', '7', '9'}},
         false);
    return 0;
}
