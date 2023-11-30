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
    test({3, 3, 5, 0, 0, 3, 1, 4}, 6);
    test({1, 2, 3, 4, 5}, 4);
    test({7, 6, 4, 3, 1}, 0);
    return 0;
}
