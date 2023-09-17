#include "../inc.h"

class Solution {
   public:
    long long totalCost(vector<int>& costs, int k, int candidates) {}
};

void test(vector<int>&& costs, int k, int candidates, long long expect) {
    auto c_param = costs;
    Solution so;
    auto ret = so.totalCost(costs, k, candidates);
    assert_eq_ret(expect, ret);
    print("costs:", c_param);
    print("k:", k, " candidates:", candidates);
}

int main() {
    test({10, 1, 11, 10}, 2, 1, 11);
    test({17, 12, 10, 2, 7, 2, 11, 20, 8}, 3, 4, 11);
    test({1, 2, 4, 1}, 3, 3, 4);
    return 0;
}
