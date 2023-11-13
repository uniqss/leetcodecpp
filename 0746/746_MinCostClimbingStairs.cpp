#include "../inc.h"

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {}
};

void test(vector<int>&& cost, int expect) {
    auto c_param = cost;
    Solution so;
    auto ret = so.minCostClimbingStairs(cost);
    assert_eq_ret(expect, ret);
    print(c_param);
}

int main() {
    test({10, 15, 20}, 15);
    test({1, 100, 1, 1, 1, 100, 1, 1, 100, 1}, 6);
    return 0;
}
