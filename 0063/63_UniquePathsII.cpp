#include "../inc.h"

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {}
};

void test(vector<vector<int>>&& obstacleGrid, int expect) {
    save4print(obstacleGrid);
    assert_eq_ret(expect, Solution().uniquePathsWithObstacles(obstacleGrid));
}

int main() {
    test({{1}}, 0);
    test({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 2);
    test({{0, 1}, {0, 0}}, 1);
    return 0;
}
