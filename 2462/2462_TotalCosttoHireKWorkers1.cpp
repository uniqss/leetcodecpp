#include "../inc.h"

// 看题一定要看仔细，，，细节害死人  相等时要取 with the smallest index... wtf
class Solution {
   public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ql, qr;
        int n = costs.size(), l = 0, r = n - 1;
        for (int i = 0; i < candidates && l <= r; ++i) {
            ql.emplace(costs[l], l), ++l;
            if (l <= r) qr.emplace(costs[r], r), --r;
        }
        long long ret = 0;
        for (int i = 0; i < k; ++i) {
            if (ql.empty())
                ret += qr.top().first, qr.pop();
            else if (qr.empty())
                ret += ql.top().first, ql.pop();
            else {
                if (ql.top() < qr.top()) {
                    ret += ql.top().first;
                    ql.pop();
                    if (l <= r) ql.emplace(costs[l], l), ++l;
                } else {
                    ret += qr.top().first;
                    qr.pop();
                    if (l <= r) qr.emplace(costs[r], r), --r;
                }
            }
        }
        return ret;
    }
};

void test(vector<int>&& costs, int k, int candidates, long long expect) {
    save4print(costs, k, candidates);
    assert_eq_ret(expect, Solution().totalCost(costs, k, candidates));
}

int main() {
    test({31, 25, 72, 79, 74, 65, 84, 91, 18, 59, 27, 9, 81, 33, 17, 58}, 11, 2, 423);
    test({10, 1, 11, 10}, 2, 1, 11);
    test({17, 12, 10, 2, 7, 2, 11, 20, 8}, 3, 4, 11);
    test({1, 2, 4, 1}, 3, 3, 4);
    return 0;
}
