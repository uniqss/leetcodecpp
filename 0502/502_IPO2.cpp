#include "../inc.h"

// 中文官方题解，还是蛮经典的思路，先成本排序，能cover到的慢慢入优先队列，管入不管出，用的自己出，能入必可用，完美的利用的题目的特征
class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), curr = 0;
        vector<pair<int, int>> vii;
        for (int i = 0; i < n; ++i) vii.emplace_back(capital[i], profits[i]);
        sort(vii.begin(), vii.end());
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < k; ++i) {
            while (curr < n && vii[curr].first <= w) q.emplace(vii[curr].second), ++curr;
            if (!q.empty())
                w += q.top(), q.pop();
            else
                break;
        }
        return w;
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
