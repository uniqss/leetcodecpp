#include "../inc.h"

class Solution {
   public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> nearbys = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
        int m = board.size(), n = board[0].size();
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                int alive = 0;
                for (auto [px, py] : nearbys) {
                    px += x, py += y;
                    if (px >= 0 && px < m && py >= 0 && py < n && (board[px][py] % 10 == 1)) ++alive;
                }
                if (board[x][y] > 0) {
                    if (alive < 2 || alive > 3) board[x][y] = 11;
                } else {
                    if (alive == 3) board[x][y] = 10;
                }
            }
        }
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (board[x][y] == 11)
                    board[x][y] = 0;
                else if (board[x][y] == 10)
                    board[x][y] = 1;
            }
        }
    }
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
