#include "../inc.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices) {}
};

void test(vector<int>&& prices, int expect) {
    Solution so;
    auto ret = so.maxProfit(prices);
    if (ret == expect) {
        print("ok.");
    } else {
        print("not ok.");
        print(prices);
        print(expect);
        print(ret);
        print();
    }
}

int main() {
    test({7, 1, 5, 3, 6, 4}, 5);
    test({1, 2}, 1);
    test({7, 6, 4, 3, 1}, 0);
    return 0;
}
