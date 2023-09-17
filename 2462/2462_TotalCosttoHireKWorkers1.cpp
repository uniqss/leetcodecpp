#include "../inc.h"

class Solution {
   public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long curr = 0, ret = 0;
        int csize = costs.size(), l = 0, r = csize - 1;
        priority_queue<int, vector<int>, greater<int>> q1, q2;
        for (int i = 0; i < candidates && l <= r; ++i) {
            q1.emplace(costs[l]);
            ++l;
        }
        for (int i = 0; i < candidates && l <= r; ++i) {
            q2.emplace(costs[r]);
            --r;
        }
        for (int i = 0; i < k; ++i) {
            int v1 = INT_MAX, v2 = INT_MAX;
            if (!q1.empty()) v1 = q1.top();
            if (!q2.empty()) v2 = q2.top();
            if (v1 <= v2) {
                ret += v1;
                q1.pop();
                if (l <= r) q1.emplace(costs[l++]);
            } else {
                ret += v2;
                q2.pop();
                if (l <= r) q2.emplace(costs[r--]);
            }
        }

        return ret;
    }
};

void test(vector<int>&& costs, int k, int candidates, long long expect) {
    auto c_param = costs;
    Solution so;
    auto ret = so.totalCost(costs, k, candidates);
    assert_eq_ret(expect, ret);
    print("costs:", c_param);
    print("k:", k, " candidates:", candidates);
}

int main() {
    test({10, 1, 11, 10}, 2, 1, 12);
    test({17, 12, 10, 2, 7, 2, 11, 20, 8}, 3, 4, 11);
    test({1, 2, 4, 1}, 3, 3, 4);
    return 0;
}
