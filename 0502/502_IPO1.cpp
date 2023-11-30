#include "../inc.h"

// 开始看错题了，他这个profit是纯的，净的，capital不会消失  这样来回倒腾，效率居然只有cpu 5%
class Solution {
    struct ProfitCmp {
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
            return pair<int, int>(lhs.second, -lhs.first) < pair<int, int>(rhs.second, -rhs.first);
        }
    };

   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // pair<capital, profit>
        queue<pair<int, int>> q1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, ProfitCmp> q2;
        int n = profits.size(), curr = w;
        for (int i = 0; i < n; ++i) {
            q2.emplace(capital[i], profits[i]);
        }
        while (--k >= 0) {
            while (!q1.empty()) q2.emplace(q1.front()), q1.pop();
            while (!q2.empty()) {
                if (q2.top().first <= curr) {
                    break;
                }
                q1.emplace(q2.top()), q2.pop();
            }
            if (q2.empty() || q2.top().first > curr) break;
            curr += q2.top().second;
            q2.pop();
        }
        return curr;
    }
};

void test(int k, int w, vector<int>&& profits, vector<int>&& capital, int expect) {
    save4print(k, w, profits, capital);
    assert_eq_ret(expect, Solution().findMaximizedCapital(k, w, profits, capital));
}

int main() {
    test(11, 11, {3, 2, 1}, {13, 12, 11}, 17);
    test(11, 11, {1, 2, 3}, {11, 12, 13}, 17);
    test(1, 2, {1, 2, 3}, {1, 1, 2}, 5);
    test(2, 0, {1, 2, 3}, {0, 1, 1}, 4);
    test(3, 0, {1, 2, 3}, {0, 1, 2}, 6);
    return 0;
}
