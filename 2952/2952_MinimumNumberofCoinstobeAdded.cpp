#include "../inc.h"

class Solution {
   public:
    int minimumAddedCoins(vector<int>& coins, int target) {}
};

void test(vector<int>&& coins, int target, int expect) {
    save4print(coins, target);
    assert_eq_ret(expect, Solution().minimumAddedCoins(coins, target));
}

int main() {
    test({15, 1, 12}, 43, 4);
    test({1, 4, 10}, 19, 2);
    test({1, 4, 10, 5, 7, 19}, 19, 1);
    test({1, 1, 1}, 20, 3);
    return 0;
}
