#include "../inc.h"

// 翻车翻了1024次。。。。。。fuck
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startneg = 0, n = gas.size(), sum = 0, total = 0, ret = -1, remain, i = 0;
        while (gas[i] - cost[i] < 0) {
            startneg += gas[i] - cost[i];
            if (++i >= n) return -1;
        }
        for (; i < n; ++i) {
            remain = gas[i] - cost[i];
            if (i == n - 1) remain += startneg;
            total += remain;
            if (sum + remain >= 0) {
                if (ret == -1) ret = i;
                sum += remain;
            } else {
                ret = -1;
                sum = 0;
            }
        }
        return total >= 0 ? ret : -1;
    }
};

void test(vector<int>&& gas, vector<int>&& cost, int expect) {
    save4print(gas, cost);
    assert_eq_ret(expect, Solution().canCompleteCircuit(gas, cost));
}

int main() {
    test({1, 1, 3}, {2, 2, 1}, 2);
    test({4}, {5}, -1);
    // {-2, -2, -2, 3, 3}
    test({4, 5, 3, 1, 4}, {5, 4, 3, 4, 2}, -1);
    test({3, 3, 4}, {3, 4, 4}, -1);
    test({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}, 3);
    test({2, 3, 4}, {3, 4, 3}, -1);
    return 0;
}