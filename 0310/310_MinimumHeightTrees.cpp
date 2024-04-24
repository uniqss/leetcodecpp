#include "../inc.h"

class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {}
};

void test(int n, vector<vector<int>>&& edges, vector<int>&& expect) {
    save4print(n, edges);
    sort(expect.begin(), expect.end());
    auto ret = Solution().findMinHeightTrees(n, edges);
    sort(ret.begin(), ret.end());
    assert_eq_ret(expect, ret);
}

int main() {
    test(4, {{1, 0}, {1, 2}, {1, 3}}, {1});
    test(6, {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}}, {3, 4});
    test(1, {}, {0});
    return 0;
}
