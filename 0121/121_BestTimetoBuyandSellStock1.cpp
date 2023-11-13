#include "../inc.h"

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e8;
        int maxprifit = 0;
        int historymin = inf;
        for (int price : prices) {
            maxprifit = max(maxprifit, price - historymin);
            historymin = min(historymin, price);
        }
        return maxprifit;
    }
};

void test(vector<int>&& prices, int expect) {
    save4print(prices);
    assert_eq_ret(expect, Solution().maxProfit(prices));
}

int main() {
    test({7, 1, 5, 3, 6, 4}, 5);
    test({1, 2}, 1);
    test({7, 6, 4, 3, 1}, 0);
    return 0;
}
