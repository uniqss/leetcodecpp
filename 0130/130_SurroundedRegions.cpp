#include "../inc.h"

class Solution {
   public:
    void solve(vector<vector<char>>& board) {}
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
