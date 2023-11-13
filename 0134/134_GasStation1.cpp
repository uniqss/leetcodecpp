#include "../inc.h"

/*
硬刚过了，但是性能堪忧。这个中间数据结构貌似是多余的，只要小心处理，能用真O(1)扫完全场
*/
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<pair<int, int>> remain2idx;
        int n = gas.size(), sum = 0;
        for (int i = 0; i < n; ++i) {
            int remain = gas[i] - cost[i];
            sum += remain;
            if (remain2idx.empty() ||
                ((remain2idx.back().first > 0 && remain < 0) || (remain2idx.back().first < 0 && remain > 0))) {
                remain2idx.emplace_back(remain, i);
            } else {
                remain2idx.back().first += remain;
            }
        }
        if (sum < 0) return -1;
        int remaincount = remain2idx.size(), i = 0;
        sum = 0;
        if (remain2idx[0].first < 0) {
            ++i;
            if (remain2idx[remaincount - 1].first < 0) {
                remain2idx[remaincount - 1].first += remain2idx[0].first;
            } else {
                remain2idx.emplace_back(remain2idx[0]);
                ++remaincount;
            }
        }
        int ret = i;
        for (; i < remaincount; ++i) {
            if (sum == 0 && remain2idx[i].first > 0) ret = remain2idx[i].second;
            if (sum + remain2idx[i].first >= 0) {
                sum += remain2idx[i].first;
            } else {
                sum = 0;
                ret = -1;
            }
        }
        return ret;
    }
};

void test(vector<int>&& gas, vector<int>&& cost, int expect) {
    save4print(gas, cost);
    assert_eq_ret(expect, Solution().canCompleteCircuit(gas, cost));
}

int main() {
    test({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}, 3);
    test({2, 3, 4}, {3, 4, 3}, -1);
    return 0;
}