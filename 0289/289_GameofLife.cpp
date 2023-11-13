#include "../inc.h"

class Solution {
   public:
    void gameOfLife(vector<vector<int>>& board) {}
};

void test(vector<vector<int>>&& board, const vector<vector<int>>& expect) {
    save4print(board);
    Solution so;
    so.gameOfLife(board);
    assert_eq_ret(expect, board);
}

int main() {
    test({{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}}, {{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}});
    test({{1, 1}, {1, 0}}, {{1, 1}, {1, 1}});
    return 0;
}
