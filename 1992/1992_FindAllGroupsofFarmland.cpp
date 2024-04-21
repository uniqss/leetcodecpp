#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {}
};

void test(vector<vector<int>>&& land, vector<vector<int>>&& expect) {
    sort(expect.begin(), expect.end());
    auto ret = Solution().findFarmland(land);
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test({{1, 0, 0}, {0, 1, 1}, {0, 1, 1}}, {{0, 0, 0, 0}, {1, 1, 2, 2}});
    test({{1, 1}, {1, 1}}, {{0, 0, 1, 1}});
    test({{0}}, {});
    return 0;
}
