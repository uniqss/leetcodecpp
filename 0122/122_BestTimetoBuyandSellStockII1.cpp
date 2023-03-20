#include "../inc/inc.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        if (prices.size() <= 1) return ret;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i + 1] > prices[i]) ret += prices[i + 1] - prices[i];
        }
        return ret;
    }
};

void test(vector<int>&& prices, int expect) {
    vector<int> prices_param = prices;
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
    test({7, 1, 5, 3, 6, 4}, 7);
    test({7, 6, 4, 3, 1}, 0);
    test({1, 2}, 1);
    return 0;
}
