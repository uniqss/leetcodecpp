#include "../inc.h"

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.emplace_back(0);
        int csize = cost.size();
        vector<int> dict(csize, INT_MAX);
        for (int i = 0; i < csize; ++i) {
            if (i <= 1)
                dict[i] = min(dict[i], cost[i]);
            else {
                dict[i] = min(dict[i - 1] + cost[i], dict[i - 2] + cost[i]);
            }
        }
        return dict[csize - 1];
    }
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
