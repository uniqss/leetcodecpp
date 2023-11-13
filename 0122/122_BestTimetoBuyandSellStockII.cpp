#include "../inc.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices) {}
};

void test(vector<int>&& prices, int expect) {
    save4print(prices);
    assert_eq_ret(expect, Solution().maxProfit(prices));
}

int main() {
    test({7, 1, 5, 3, 6, 4}, 7);
    test({7, 6, 4, 3, 1}, 0);
    test({1, 2}, 1);
    return 0;
}
