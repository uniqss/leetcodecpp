#include "../inc.h"

class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {}
};

void test(int k, vector<int>&& prices, int expect) {
    save4print(k, prices);
    assert_eq_ret(expect, Solution().maxProfit(k, prices));
}

int main() {
    test(2, {2, 4, 1}, 2);
    test(2, {3, 2, 6, 5, 0, 3}, 7);
    return 0;
}
