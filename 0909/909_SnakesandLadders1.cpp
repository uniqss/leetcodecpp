#include "../inc.h"

// 终于看懂题了
class Solution {
   public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), n2 = n * n;
        queue<pair<int, int>> q;
        vector<bool> vis(n2);
        q.emplace(0, 0);
        while (!q.empty()) {
            auto [curr, currStep] = q.front();
            q.pop();
            for (int i = 1; i <= 6 && curr + i < n2; ++i) {
                int next = curr + i;
                int x = n - next / n - 1;
                int y = next % n;
                if ((n - x) % 2 == 0) y = n - y - 1;
                if (board[x][y] > 0) next = board[x][y] - 1;
                if (next == n2 - 1) return currStep + 1;
                if (!vis[next]) q.emplace(next, currStep + 1), vis[next] = true;
            }
        }
        return -1;
    }
};

void test(vector<vector<int>>&& board, int expect) {
    save4print(board);
    auto ret = Solution().snakesAndLadders(board);
    assert_eq_ret(expect, ret);
}

int main() {
    test({{-1, -1, -1, -1, -1, -1},
          {-1, -1, -1, -1, -1, -1},
          {-1, -1, -1, -1, -1, -1},
          {-1, 35, -1, -1, 13, -1},
          {-1, -1, -1, -1, -1, -1},
          {-1, 15, -1, -1, -1, -1}},
         4);
    test({{-1, -1}, {-1, 3}}, 1);
    return 0;
}
