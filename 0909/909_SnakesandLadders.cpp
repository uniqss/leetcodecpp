#include "../inc.h"

class Solution {
   public:
    int snakesAndLadders(vector<vector<int>>& board) {}
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
