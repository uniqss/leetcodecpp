#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> combinationSum3(int k, int n) {}
};

void test(int k, int n, vector<vector<int>>&& expect) {
    save4print(k, n);
    sortvvrawInnerAndOuter(expect);
    auto ret = Solution().combinationSum3(k, n);
    sortvvrawInnerAndOuter(ret);
    assert_eq_ret(expect, ret);
}

int main() {
    test(3, 7, {{1, 2, 4}});
    test(3, 9, {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}});
    test(4, 1, {});
    return 0;
}
