#include "../inc.h"

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {}
};

void test(vector<int>&& coins, int amount, int expect) {
    Solution so;
    auto ret = so.coinChange(coins, amount);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(coins);
        print(amount);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({1, 2}, 2, 1);
    test({2147483647}, 2, -1);
    test({1, 2, 5}, 11, 3);
    test({2}, 3, -1);
    test({1}, 0, 0);
    return 0;
}
