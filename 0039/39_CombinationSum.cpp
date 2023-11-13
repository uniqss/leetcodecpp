#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {}
};

void test(vector<int>&& candidates, int target, const vector<vector<int>>& expect) {
    save4print(candidates, target);
    assert_eq_ret(expect, Solution().combinationSum(candidates, target));
}

int main() {
    test({2, 3, 6, 7}, 7, {{2, 2, 3}, {7}});
    test({2, 3, 5}, 8, {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}});
    test({2}, 1, {});
    return 0;
}