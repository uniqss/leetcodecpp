#include "../inc.h"

class Solution {
   public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {}
};

void test(vector<int>&& nums, int k, const vector<vector<int>>& expect) {
    save4print(nums, k);
    assert_eq_ret(expect, Solution().divideArray(nums, k));
}

int main() {
    test({1, 3, 4, 8, 7, 9, 3, 5, 1}, 2, {{1, 1, 3}, {3, 4, 5}, {7, 8, 9}});
    test({1, 3, 3, 2, 7, 3}, 3, {});
    return 0;
}
