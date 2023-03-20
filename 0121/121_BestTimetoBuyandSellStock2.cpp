#include "../inc.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int begin = 0, end = prices.size() - 1;
        while (begin < end && prices[begin] > prices[begin + 1]) ++begin;
        while (begin < end && prices[end] < prices[end - 1]) --end;
        if (begin >= end) return 0;

        int inf = 1e8;
        int maxprifit = 0;
        int historymin = inf;
        for (int i = begin; i <= end; ++i) {
            int price = prices[i];
            maxprifit = max(maxprifit, price - historymin);
            historymin = min(historymin, price);
        }
        return maxprifit;
    }
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
